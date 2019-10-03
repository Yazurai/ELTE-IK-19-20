-- 11.GYAKORLAT
import Data.List

dropSpaces :: String -> String
dropSpaces xs = dropWhile (\x -> x == ' ') xs

trim :: String -> String
trim xs = takeWhile (not.isZero) $ dropWhile (isZero) xs
    where
        isZero x = x == ' '

--Spec says to use 'word', but you should use 'words' and 'unwords'
monogram :: String -> String
monogram name = unwords $ map ((++".").take 1) (words name)

--In the test cases on has the wrong order (uniq "papagaj" == "ajgp" instead of uniq "papagaj" == "agjp")
uniq :: Ord a => [a] -> [a]
uniq = (map head).group.sort

repeated :: Ord a => [a] -> [a]
repeated = (map head).(filter (\x -> (length x) > 1)).group.sort

zipWith' :: (a -> a -> a) -> [a] -> [a] -> [a]
zipWith' f (x:xs) (y:ys) = f x y : zipWith' f xs ys 
zipWith' _ _ _          = []

dotProduct :: [Int] -> [Int] -> Int
dotProduct xs ys = foldl (+) 0 $ zipWith (*) xs ys

isPrime :: Int -> Bool
isPrime n 
    |n <= 1    = False
    |otherwise = 2 == (length $ filter (\x -> n `mod` x == 0) [1..n])

primes :: [Int]
primes = filter isPrime [1..]

iterate'' :: (a -> a) -> a -> [a]
iterate'' f n = n : iterate'' f (f n)

fibonacci :: [Int]
fibonacci = map fst $ iterate'' (\(a,b) -> (b,a+b)) (0,1)