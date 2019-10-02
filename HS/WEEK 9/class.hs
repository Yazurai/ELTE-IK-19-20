-- 8.GYAKORLAT

take' :: Int -> [a] -> [a]
take' _ [] = []
take' 0 _ = []
take' n (x:xs) = x:(take' (n-1) xs)

drop' :: Int -> [a] -> [a]
drop' _ [] = []
drop' 0 xs = xs
drop' n (s:st) = drop' (n-1) st

--We will use this splitOn from the previous practice sheet
splitOn :: Char -> String -> [String]
splitOn _ "" = [""]
splitOn c (t:ts)
    |c == t = "":current:remaining
    |otherwise = (t:current):remaining
    where
        current:remaining = splitOn c ts

langAndRegion :: String -> (String, String)
langAndRegion txt = (parts!!0, parts!!1)
    where
        parts = splitOn '-' txt

zip' :: [a] -> [b] -> [(a,b)]
zip' [] _ = []
zip' _ [] = []
zip' (a:as) (b:bs) = (a,b):(zip' as bs)

unzip' :: [(a,b)] -> ([a], [b])
unzip' [] = ([], [])
unzip' ((a,b):xs) = (a:as, b:bs)
    where
        (as,bs) = unzip' xs

empty :: String -> [Int]
empty [] = []
empty text = [x | x <- [1..lnCount], (lns!!(x-1)) == []]
    where
        lnCount = length (lns)
        lns = lines text

splitAt' :: Int -> [a] -> ([a], [a])
splitAt' _ [] = ([], [])
splitAt' 0 xs = ([],xs)
splitAt' num (x:xs) = ((x:y),ys)
    where
        (y,ys) = splitAt' (num-1) xs

nub' :: Eq a => [a] -> [a]
nub' [] = []
nub' xs = nub'' xs []
    where
        nub'' [] _ = []
        nub'' (x:xs) founds
            |x `elem` founds = nub'' xs founds 
            |otherwise       = x : nub'' xs (x:founds)

concat' :: [[a]] -> [a]
concat' [] = []
concat' (x:xs) = x ++ (concat' xs)