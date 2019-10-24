import Data.Char
import Data.List

emptyData :: ([Int],[Int])
emptyData = ([], take 300 (cycle [0]))

readPtr :: ([a],[a]) -> a
readPtr (_,x:xs) = x

ptrInc :: ([a],[a]) -> ([a],[a])
ptrInc (xs, y:ys) = (xs++[y], ys)

ptrDec :: ([a],[a]) -> ([a],[a])
ptrDec (xs,ys) = (init xs,(last xs):ys)

writePtr :: Integral a => ([a],[a]) -> a -> ([a],[a])
writePtr (xs, y:ys) n = (xs, newY:ys)
    where 
        newY = n `mod` 256

every :: Int -> [a] -> [a]
every n xs = [xs!!y | y <- [0..(length xs - 1)], y `mod` n == 0]

modifyPtr :: Integral a => (a -> a) -> ([a],[a]) -> ([a],[a])
modifyPtr f (xs, y:ys) = (xs, (f y):ys)

--This deletes all occurences of ']'
getLoopBody :: String -> (String,String)
getLoopBody xs = foldr (\x (acc,rmd) -> if x == ']' && rmd == "" then ("",acc) else (x:acc,rmd)) ("","") xs

--This is the correct version, it might be possible to do with a fold
getLoopBody' :: String -> (String,String)
getLoopBody' [] = ("","")
getLoopBody' (x:xs)
    |x == ']' && rmd == "" = ("",acc)
    |otherwise             = (x:acc,rmd)
    where
        (acc,rmd) = getLoopBody' xs

loopUntil :: (a -> Bool) -> (a -> a) -> Int -> a -> a
loopUntil check f n x 
    |check newElem = newElem
    |otherwise = loopUntil check f n newElem
    where
        newElem = (iterate f x)!!n

--Doesnt work for nested loops.
--The issue seems to be with not being able to predetermine the loop length for the loopuntil function
--Tried to do it with countlength but that still doesnt solve the issue 
run :: (([Int],[Int]),(String,String)) -> (([Int],[Int]),(String,String))
run (memory,('>':cs, ds)) = (ptrInc memory, (cs,ds))
run (memory,('<':cs, ds)) = (ptrDec memory, (cs,ds))
run (memory,('+':cs, ds)) = (modifyPtr (+1) memory, (cs,ds))
run (memory,('-':cs, ds)) = (modifyPtr (+(-1)) memory, (cs,ds))
run (memory,('.':cs, ds)) = (memory, (cs,ds++[chr(readPtr memory)] ))
run (memory,('[':cs, ds))
    |readPtr memory == 0  = (memory,(rnd,ds))
    |otherwise            = ((m1,m2),(rnd,out))
    where
        (loopBody,rnd)    = getLoopBody cs
        ((m1,m2),(c,out)) = loopUntil (\(m,_) -> readPtr m == 0) run (countLength loopBody) (memory,(cycle loopBody, ds))
run (m, c)                = (m, c)

countLength :: String -> Int
countLength [] = 0
countLength (x:xs)
    |x == '['  = 1
    |otherwise = countLength xs + 1

interpret cs = out
    where
        (_,(_,out)) = last (take (length cs + 1) $ iterate run (emptyData,(cs,"")))
