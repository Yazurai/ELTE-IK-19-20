isAmenable :: Int -> Bool
isAmenable x 
    |x == 4 = False
    |otherwise = x `rem` 4 == 0 || x `rem` 4 == 1 

upgrade :: (String, String, Int) -> (String, String, Int, Bool)
upgrade (model, brand, year) = (model, brand, year, year < 2000 && brand == "Ford" || brand == "Suzuki")

expandPath :: String -> String -> String
expandPath home ('~':'/':xs) = home ++ ('/':xs)
expandPath _ xs = xs

binom :: Integer -> Integer -> Integer
binom n k = nfact `div` bottom
    where
        nfact = foldl (*) 1 [1..n]
        kfact = foldl (*) 1 [1..k]
        bottom = (foldl (*) 1 [1..(n-k)]) * kfact

quasiMagicSquare :: [[Int]] -> Bool
quasiMagicSquare xs = all (==(sums!!0)) sums
    where
        sums = map (sum) xs

simpleGrep :: String -> String -> [(String, Int)]
simpleGrep w txt = filter (\(line,_) -> if length (words line) > 0 then (words line)!!0 == w else False) list
    where
        list = zip (lines txt) [1..]

hasNotTranslator :: [(String, String)] -> [(String, String, String)] -> [String]
hasNotTranslator langs ppl = map (fst) $ filter (\(_,l) -> length(filter (\(_,_,l2) -> l == l2) ppl) == 0 ) langs
