import Data.Char

isDivs :: (Int, Int) -> Int -> Bool
isDivs (a,b) x = a `rem` x == 0 || b `rem` x == 0

numberedABC :: Char -> [(Int,Char)]
numberedABC c = take pos $ zip [1..] ['a'..]
    where
        pos = ord c - ord 'a' + 1
        
squareSum :: [Int] -> Int
squareSum xs = sum $ map (^2) xs

greatCoord :: (Int,Int) -> Bool
greatCoord (x,y)
    |x `rem` 10 == 0 && y == 2 * x = True
    |otherwise = False

scholars :: [(String, String, Double)] -> Double -> [String]
scholars xs x = [ name++" - "++code | (name, code, avg) <- xs, avg >= x]

howMany :: [Char] -> Char -> Int
howMany xs c = length $ filter (==c) xs

leaveSeconds :: [Char] -> [Char]
leaveSeconds xs = [xs!!i| i <- [0..(length xs - 1)], i `rem` 2 == 0]