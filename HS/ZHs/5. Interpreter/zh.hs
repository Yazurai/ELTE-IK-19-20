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

getLoopBody :: String -> (String,String)
getLoopBody xs = foldr (\x (acc,rmd) -> if x == ']' && rmd == "" then ("",acc) else (x:acc,rmd)) ("","") xs

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

run :: (([Int],[Int]),(String,String)) -> (([Int],[Int]),(String,String))
run (memory,('>':cs, ds)) = (ptrInc memory, (cs,ds))
run (memory,('<':cs, ds)) = (ptrDec memory, (cs,ds))
run (memory,('+':cs, ds)) = (modifyPtr (+1) memory, (cs,ds))
run (memory,('-':cs, ds)) = (modifyPtr (+(-1)) memory, (cs,ds))
run (memory,('.':cs, ds)) = (memory, (cs,ds++[chr(readPtr memory)] ))
run (memory,('[':cs, ds)) = state
    where
        (loopBody,rnd) = getLoopBody ds
        state = loopUntil ((readPtr memory) == 0) run 1 (memory,(loopBody, ds))
run (m, c)                = (m, c)

interpret :: String -> String
interpret cs = out
    where
        (_,(_,out)) = last (iterate run (emptyData,(cs,"")))
