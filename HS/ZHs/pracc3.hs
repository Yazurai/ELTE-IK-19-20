import Data.Char

hasFever :: Double -> Bool
hasFever f = (f-32)/1.8 > 38 

positiveProduct :: [Int] -> Int
positiveProduct xs = foldl (*) 1 $ filter (>0) xs

mightyGale :: [(String, Int, Int, Int)] -> String
mightyGale xs
    |length found == 0 = []
    |otherwise         = found!!0
    where
        found = [a | (a,_,c,_) <- xs, c > 110]

cipher :: String -> String
cipher (x1:x2:x3:xs)
    |isLetter x1 && isLetter x2 && isDigit x3 = [x1,x2]
    |length xs < 0 = ""
    |otherwise = cipher (x2:x3:xs)
cipher _ = ""

pizza :: [(String, Int)] -> Int
pizza xs = 500 + sum [price | (_,price) <- xs]

listDiff :: String -> String -> String
listDiff xs ys = filter (\x -> not (x `elem` ys)) xs

validGame :: String -> Bool
validGame xs = good
    where
        (good,_) = foldl (\(good,c) x -> if (x!!0) == c then (good,x!!(length x - 1)) else (False,x!!(length x - 1)) ) (True, ws!!0!!0) ws
        ws = words xs
