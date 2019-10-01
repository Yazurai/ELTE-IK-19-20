-- 7.GYAKORLAT
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
--Also has a faster running time than using the basic sort function above
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

--the first version gives back an empty string for an empty string
--This is needed for the pattern matching in the where clause

--I like the pattern matching version a bit more, find it a tad bit more elegant
--If you wanted to be like the spec, then use head and tail instead of pattern matching(version 2)
splitOn :: Char -> String -> [String]
splitOn _ "" = [""]
splitOn c (t:ts)
    |c == t = "":current:remaining
    |otherwise = (t:current):remaining
    where
        current:remaining = splitOn c ts

splitOn2 :: Char -> String -> [String]
splitOn2 _ "" = [""]
splitOn2 c (t:ts)
    |c == t = "":remaining
    |otherwise = (t:head remaining):tail remaining
    where
        remaining = splitOn c ts


csv :: String -> [[String]]
csv ts = [tokens| line <- lines ts, let tokens = splitOn ',' line]