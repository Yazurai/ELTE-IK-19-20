-- 10.GYAKORLAT
import Data.Char

map' :: (a -> b) -> [a] -> [b]
map' _ [] = []
map' f (x:xs) = f(x):(map' f xs) 

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ [] = []
filter' f (x:xs) = if f(x) then x:(filter' f xs) else filter' f xs

upperToLower :: String -> String
upperToLower [] = []
upperToLower txt = map (toLower) (filter (`elem` ['A'..'Z']) txt)

all' :: (a -> Bool) -> [a] -> Bool
all' _ [] = True
all' f xs = foldr (&&) True (map (f) xs)

any' :: (a -> Bool) -> [a] -> Bool
any' _ [] = False
any' f xs = foldr (||) False (map (f) xs)

hasLongLines :: String -> Bool
hasLongLines [] = False
hasLongLines xs = any' (>= 3) $ map (length . words) (lines xs)

--Spec says it returns a [a] but the test cases suggest a boolean value
--Test cases seem to imply elem to be case insensitive while haskell is sensitive by default
--The default elem is also case insensitive
elem' :: (Eq a) => a -> [a] -> Bool
elem' v xs = any' (== v) xs

hasAny :: Eq a => [a] -> [a] -> Bool
hasAny as xs = any' (`elem'` xs) as

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' f = foldr (\x acc -> if f(x) then x:acc else []) []

takeWhile'' :: (a -> Bool) -> [a] -> [a]
takeWhile'' f = foldl (\acc x -> if f(x) then acc++[x] else acc) []

--Tried doing it with foldr, but there would be a need for an additional accumulator or a helper bool
--At which point I found it just more convinient to use simple recursion for simplicity
dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' f (x:xs) 
    | f(x)      = dropWhile' f xs
    | otherwise = x:xs

dropWord :: String -> String
dropWord [] = []
dropWord xs = dropWhile (\x -> x /= ' ') xs

users :: [(String, String)]
users = [ ("mrbean", "4321"), ("admin", "s3cr3t"), ("finn", "algebraic")]

doesUserExist :: String -> [(String, String)] -> Bool
doesUserExist val (d:ds) = elem val [username | (username,_) <- (d:ds)]

insertAt :: Int -> Char -> [Char] -> [Char]
insertAt 0 c xs = c:xs
insertAt n c [] = [c]
insertAt n c (x:xs) = x:(insertAt (n-1) c xs) 