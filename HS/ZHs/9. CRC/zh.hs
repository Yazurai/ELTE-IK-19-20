import Data.Char
import Data.Bits

toBinary :: Int -> [Int]
toBinary x = reverse (toBinary' x)

toBinary' :: Int -> [Int]
toBinary' 0 = []
toBinary' x
    |x `mod` 2 == 1 = 1 : toBinary' (x `div` 2)
    |otherwise      = 0 : toBinary' (x `div` 2)

chrToBinary :: Char -> [Int]
chrToBinary c = format' 9 $ toBinary (ord c)

format' :: Int -> [Int] -> [Int]
format' n xs = take (n - (length xs) - 1) (cycle [0]) ++ xs

strToBinary :: String -> [Int]
strToBinary xs = foldr (++) [] $ map (chrToBinary) xs

bxor :: [Int] -> [Int] -> [Int]
bxor xs ys
    |length xs < length ys = [ xor (fxs!!i) (fys!!i) | i <- [0..(maxL-1)]]
    |length xs > length ys = [ xor (fxs!!i) (fys!!i) | i <- [0..(maxL-1)]]
    |otherwise             = [ xor (fxs!!i) (fys!!i) | i <- [0..(maxL-1)]]
    where
        fxs = format'' maxL xs
        fys = format'' maxL ys
        maxL = (max (length xs) (length ys))

format'' :: Int -> [Int] -> [Int]
format'' n xs = xs ++ take (n - (length xs)) (cycle [0])

(%>=%) :: [Int] -> [Int] -> Bool
(%>=%) [] [] = True
(%>=%) _ [] = True
(%>=%) [] _ = False
(%>=%) (x:xs) (y:ys)
    |x == 1    = True
    |y == 1    = False
    |otherwise = (%>=%) xs ys

bmod :: [Int] -> [Int] -> [Int]
bmod divident divisor
    |length divident < len          = divident
    |take len divident %>=% divisor = bmod (divident `bxor` divisor) divisor
    |otherwise                      = bmod (drop 1 divident) divisor
        where
            len = length divisor

crc :: String -> [Int] -> [Int]
crc txt xs = (strToBinary txt) `bmod` xs 

