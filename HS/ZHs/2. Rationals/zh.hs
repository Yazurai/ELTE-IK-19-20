nextRational :: Rational -> Rational
nextRational x = 1/(2*y+1-x)
  where
    y = fromIntegral(floor x)

positiveRationals :: [Rational]
positiveRationals = iterate nextRational 1

merge' :: [a] -> [a] -> [a]
merge' xs     []     = xs
merge' []     ys     = ys
merge' (x:xs) (y:ys) = x : y : merge' xs ys

rationals :: [Rational]
rationals = 0:(merge' positive negative)
  where
    positive = positiveRationals
    negative = map (*(-1)) positiveRationals

rationalIndex :: Rational -> Int
rationalIndex x = [n | n <- [1..], rationals!!n == x]!!0

index :: Eq a => a -> [a] -> Int
index x xs = [n | n <- [1..], xs!!n == x]!!0