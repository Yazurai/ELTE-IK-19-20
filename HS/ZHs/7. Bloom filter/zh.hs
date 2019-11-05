import Data.Bits  
import Data.List  
import Data.Char

data BitVector = BV [Int]
  deriving (Show,Eq,Data,Typeable)

data BloomFilter = BLF BitVector
  deriving (Show,Eq,Data,Typeable)

additiveHash :: Int -> [Int] -> Int
additiveHash x xs = sum xs `mod` x

pearsonHash :: [Int] -> [Int] -> Int
pearsonHash t cs = h
    where
        (h,index) = foldr (\x (h',index') -> (t!!(h' `xor` x),h' `xor` x)) (0,0) cs

hashes :: [Int] -> [Int]
hashes xs = additive:pearson:[]
    where
        additive = additiveHash 191 xs
        pearson  = pearsonHash [255,254..0] xs

empty :: BitVector
empty = BV []

add :: BitVector -> Int -> BitVector
add (BV vs) x = BV (x:vs) 

toBloom :: BitVector -> BloomFilter
toBloom v = BLF v

bloomAdd :: BloomFilter -> [Int] -> BloomFilter
bloomAdd (BLF (BV xs)) ys = BLF (BV (hashes ys++xs))

has :: BitVector -> Int -> Bool
has (BV xs) x = x `elem` xs

bloomQuery :: BloomFilter -> [Int] -> Bool
bloomQuery (BLF v) xs = foldl (\acc x -> v `has` x && acc) True (hashes xs)

normalize :: String -> [Int]
normalize xs = map (ord.toUpper) $ filter (isLetter) xs

wordFilter :: [String] -> BloomFilter
wordFilter xs = foldl (\acc x -> bloomAdd acc (normalize x)) (toBloom empty) xs

spellCheck :: BloomFilter -> String -> [Int]
spellCheck blf xs = [ i | (w,i) <- zip wordParts indexList, not (bloomQuery blf (normalize w))]
  where
    wordParts = words xs
    indexList = [0..((length wordParts)-1)]
