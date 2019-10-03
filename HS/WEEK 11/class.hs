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
elem' _ [] = False
elem' v xs = any' (== True) $ map (== v) xs

hasAny :: Eq a => [a] -> [a] -> Bool
hasAny as xs = any' (== True) $ map (`elem'` xs) as

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' _ [] = []
takeWhile' f xs = foldr (\x acc -> if f(x) then x:acc else []]) [] xs