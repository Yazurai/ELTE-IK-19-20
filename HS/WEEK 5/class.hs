-- 4.Gyakorlat
import Data.Char

headInt :: [Int] -> Int
headInt [] = 0
headInt (x:xs) = x

tailInt :: [Int] -> Int
tailInt [] = 0
tailInt (x:xs) = tailInt xs

nullInt :: [Int] -> Bool
nullInt [] = True
nullInt xs = False

isSingletonInt :: [Int] -> Bool
isSingletonInt [] = False
isSingletonInt [x] = True
isSingletonInt xs = False

toUpperFirst :: String -> String
toUpperFirst [] = []
toUpperFirst (x:xs) = toUpper(x):xs

isLetter2 :: Char -> Bool
isLetter2 c = 64 < ord c && ord c < 123

isLetter3 :: Char -> Bool
isLetter3 c = c `elem` undercase || c `elem` uppercase
    where
        undercase = ['a'..'z']
        uppercase = ['A'..'Z']

isDigit2 :: Char -> Bool
isDigit2 c = c `elem` digits
    where
        digits = ['0'..'9']

mountain :: Int -> [Int]
mountain n = [1..n] ++ [n-1,n-2..1]

divisors :: Int -> [Int]
divisors n = [x | x <- [1..n], n `mod` x == 0]

powersOfTwo = [2^x | x <- [0..]]

osc = [if x `mod` 2 == 0 then -x else x | x <- [1..]]
leibniz = [x | x <- [1,3..]]

time = [(hour,minute) | hour <- [0..23], minute <- [0..59]]