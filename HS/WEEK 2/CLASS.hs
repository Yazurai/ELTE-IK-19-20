divides :: Int -> Int -> Bool
divides a b = b `mod` a == 0

area :: Int -> Int -> Int
area x y = x * y

triangleSides :: Int -> Int -> Int -> Bool
triangleSides a b c = aCheck && bCheck && cCheck
    where
        aCheck = a < b + c
        bCheck = b < a + c
        cCheck = c < a + b

pythagoreanTriple :: Int -> Int -> Int -> Bool
pythagoreanTriple a b c = aCheck || bCheck || cCheck
    where
        aCheck = a^2 == b^2 + c^2
        bCheck = b^2 == a^2 + c^2
        cCheck = c^2 == a^2 + b^2