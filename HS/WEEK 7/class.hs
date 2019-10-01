-- 6.GYAKORLAT
import Data.List

sum' :: [Int] -> Int
sum' [] = 0
sum' (x:xs) = x + sum' xs

last' :: [Int] -> Int
last' [x] = x
last' (x:xs) = last xs

and' :: [Bool] -> Bool
and' [] = True;
and' [b] = b;
and' (b:bs) = b && and' bs

or' :: [Bool] -> Bool
or' [] = False;
or' [b] = b;
or' (b:bs) = b || and' bs

replicate2 :: Int -> Char -> String
replicate2 0 c = ""
replicate2 n c = [c] ++ (replicate2 (n-1) c)

insert2 :: Int -> [Int] -> [Int] 
insert2 n [] = [n]
insert2 n (x:xs)
    |n <= x = n:x:xs
    |otherwise = x:(insert n xs)

sort2 :: [Int] -> [Int]
sort2 [] = []
sort2 (x:xs) = insert x (sort xs)

--Simple solution using previous answers
merge :: [Int] -> [Int] -> [Int]
merge [] _ = []
merge _ [] = []
merge as bs = sort (as ++ bs)

--The more educational solution that is self contained
merge2 :: [Int] -> [Int] -> [Int]
merge2 [] _ = []
merge2 _ [] = []
merge2 [a] (b:bs)
    |a <= b = a:b:bs
    |otherwise = b:(merge2 [a] bs)
merge2 (a:as) [b]
    |a <= b = a:(merge2 as [b])
    |otherwise = b:a:as
merge2 (a:as) (b:bs)
    |a <= b = a:(merge2 as (b:bs))
    |otherwise = b:(merge2 (a:as) bs)

mergeSort :: [Int] -> [Int]
mergeSort [] = []
mergeSort [a] = [a]
mergeSort [a,b]
    |a <= b = [a,b]
    |otherwise = [b,a]
mergeSort as = sort(mergeSort(fstPart) ++ mergeSort(scdPart))
    where
        (fstPart, scdPart) = splitAt ((length as)`div`2) as

intercalate2 :: String -> [String] -> String
intercalate2 s [] = []
intercalate2 s (c:cs) = c ++ s ++ (intercalate2 s cs)

splitOn :: Char -> String -> [String]
splitOn _ "" = []
splitOn c (t:ts)
    |c == t = splitOn c 