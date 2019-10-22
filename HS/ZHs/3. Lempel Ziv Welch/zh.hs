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
append dic x (y:ys) = dic ++ [x ++ [y]]

encode :: [String] -> String -> [Int]
encode dic [] = []
encode dic xs = i:encode newDic rmd
    where
        (i,x,rmd) = munch dic xs
        newDic = append dic x rmd

compress :: String -> String
compress xs = map (chr) encoded
    where
        encoded = encode dictionary xs

decode :: [String] -> [Int] -> String
decode dic [] = []
decode dic [x] = dic!!x
decode dic (x:y:xs)
    |y < length dic = dic!!x ++ (decode normalNewDic (y:xs))
    |otherwise      = dic!!x ++ (decode xNewDic (y:xs))
        where
            normalNewDic = append dic (dic!!x) (dic!!y)
            xNewDic      = append dic (dic!!x) (dic!!x)

decompress :: String -> String
decompress xs = decoded
    where
        converted = map (ord) xs
        decoded = decode dictionary converted
