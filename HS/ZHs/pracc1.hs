import Data.Char

both :: Char -> (Char,Char)
both c = (c,c)

diffCube :: Int -> Int -> Int
diffCube x y = (x - y) ^ 3

toLowerFirstAndThird :: String -> String
toLowerFirstAndThird xs
    |length xs < 3 = xs
    |otherwise     = (toLower (xs!!0)):(xs!!1):(toLower (xs!!2)):(drop 3 xs)

headAndBeforeLast :: String -> String
headAndBeforeLast xs = head xs:(xs!!(length xs - 2)):[]

average :: [Double] -> Double
average xs = (sum xs) / (fromIntegral(length xs))

arithmeticSequence :: Integer -> Integer -> [Integer]
arithmeticSequence s i = [s,(s+i)..]

doubleElements :: [Int] -> [Int]
doubleElements = foldr (\x acc -> x:x:acc) []