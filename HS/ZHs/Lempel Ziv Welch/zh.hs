import Data.Char
import Data.List

dictionary :: [String]
dictionary = [ [chr n] | n <- [0..127]]

prefixes :: String -> [String] -> [(Int,String)]
prefixes txt dic = [ (x,dic!!x) | x <- [0..(length dic - 1)], take (length (dic!!x)) txt == dic!!x]

longest :: [(Int,String)] -> (Int,String)
longest xs = foldl (\(accI,accXs) (i,ys) -> if length ys >= length accXs then (i,ys) else (accI,accXs) ) (0,"") xs

munch :: [String] -> String -> (Int,String,String)
munch dic xs = (i,x,rmd)
    where
        (i,x) = longest $ prefixes xs dic
        rmd = drop (length x) xs

append :: [String] -> String -> String -> [String]
append dic _ "" = dic
append dic x (y:ys) = 