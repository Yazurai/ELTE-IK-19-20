book :: (String, String, Int, Bool)
book = ("vmi konyv", "vki iro", 1978, True)

getTitle :: (String, String, Int, Bool) -> String
getTitle (title, _, _, _) = title

getAuthor :: (String, String, Int, Bool) -> String
getAuthor (_, auth, _, _) = auth

--2.GYAKORLAT

add :: (Int, Int) -> (Int, Int) -> (Int, Int)
add (a1, a2) (b1, b2) = (extA1 + extB1, common)
    where
        common = a2 * b2
        extA1 = a1 * b2
        extB1 = b1 * a2

mul :: (Int, Int) -> (Int, Int) -> (Int, Int)
mul (a1, a2) (b1, b2) = (a1 * b1, a2 * b2)

modDiv :: Int -> Int -> (Int, Int)
modDiv a b
    |b /= 0 = (a `mod` b, a `div` b)
    |otherwise = (0,0)

quadratic :: Double -> Double -> Double -> (Double, Double)
quadratic a b c = (x1, x2)
    where
        d = b^2 - 4*a*c
        x1 = (-b - sqrt(d)) / 2*a
        x2 = (-b + sqrt(d)) / 2*a

matches :: (Int, Int) -> (Int, Int) -> Bool
matches (a1, a2) (b1, b2) = case1 || case2 || case3 || case4
    where
        case1 = a1 == b1
        case2 = a1 == b2
        case3 = a2 == b1
        case4 = a2 == b2

len :: (Int, Int) -> Double
len (x, y) = sqrt(fromIntegral(abs(x)^2 + abs(y)^2))

stretch :: (Int, Int) -> Int -> (Int, Int)
stretch (x, y) n = (x*n, y*n)

distance :: (Int, Int) -> (Int, Int) -> Double
distance (x1, y1) (x2, y2) = len(distanceVector)
    where
        distanceVector = (abs(x1 - x2), abs(y1 - y2))