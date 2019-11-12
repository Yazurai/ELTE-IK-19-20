import Data.List
import Data.Char

blackStones :: (Eq a) => [a] -> [a] -> Int
blackStones xs ys = length $ filter (\(x,y) -> x == y) $ zip xs ys

whiteStones :: (Eq a) => [a] -> [a] -> Int
whiteStones xs ys = (sameElem xs ys) - (blackStones xs ys)
        
sameElem :: (Eq a) => [a] -> [a] -> Int
sameElem [] ys = 0
sameElem (x:xs) ys
    |x `elem` ys = 1 + sameElem xs (delete x ys)
    |otherwise   = sameElem xs ys
            
data Code = Code Char Char Char Char deriving (Show)

readCode :: String -> Maybe Code
readCode xs
    |count == 4 = Just (Code (nums!!0) (nums!!1) (nums!!2) (nums!!3) )
    |otherwise  = Nothing
    where
        count = length nums
        nums  = filter (isDigit) xs

toList :: Code -> [Char]
toList (Code a b c d) = a:b:c:d:[]

whiteAndBlackStones :: Code -> String -> (Int,Int)
whiteAndBlackStones cd xs
    |length xs == 4 = (whiteStones xs (toList cd), blackStones xs (toList cd))
    |otherwise      = (0, 0)
