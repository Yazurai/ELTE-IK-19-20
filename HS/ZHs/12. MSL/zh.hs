data Measure = Land Int | Sea
    deriving (Show,Eq,Data,Typeable)

type Measures = [Measure]

testMeasures1 :: Measures
testMeasures1 = []
testMeasures2 :: Measures
testMeasures2 =
  [ Land 300, Land 200, Land 400, Sea, Sea, Land 300, Land 200, Land 150, Sea
  , Land 40, Land 80, Land 500, Land 650, Land 890, Land 300, Sea, Sea, Sea
  , Sea, Land 40 ]
testMeasures3 :: Measures
testMeasures3 =
  [ Sea, Sea, Sea, Land 50, Land 100, Land 10, Sea, Land 30, Land 80, Land 350
  , Land 700, Land 980, Land 600, Land 200, Land 40, Sea, Sea, Sea, Sea ]

isLand :: Measure -> Bool
isLand (Land _) = True 
isLand _        = False

hasSea :: Measures -> Bool
hasSea = any (not.isLand)

splitSegments :: Measures -> [Measures]
splitSegments [] = []
splitSegments [m] = [[m]]
splitSegments (m:ms)
    |isLand (head x) == isLand m = (m:x):xs
    |otherwise                   = [m]:(x:xs)
    where
        x:xs = splitSegments ms

islandCount :: Measures -> Int
islandCount ms = length $ filter (\x -> isLand (head x)) segs
    where
        segs = splitSegments ms

lengthOfIslands :: Measures -> [Int]
lengthOfIslands ms = map length $ filter (\x -> isLand (head x)) segs
    where
        segs = splitSegments ms

hasIslandsOfSameLength :: Measures -> Bool
hasIslandsOfSameLength ms = any (>1) $ map (\x -> foldl (\acc y -> if x == y then acc+1 else acc) 0 ls) ls
    where
        ls = lengthOfIslands ms

highestIsland :: Measures -> Maybe Int
highestIsland ms
    |length ls == 0 = Nothing
    |otherwise      = Just $ foldl (\acc x -> if ls!!x > ls!!acc then x else acc) 0 [0..(length ls - 1)]
    where
        ls = lengthOfIslands ms

hypotenuse :: Int -> Int -> Int
hypotenuse a b = round (sqrt (fromIntegral(a*a + b*b)))

walkingDistance :: Int -> Measure -> Measure -> Int
walkingDistance n Sea Sea = n
walkingDistance n Sea (Land x) = hypotenuse n x
walkingDistance n (Land x) Sea = hypotenuse n x
walkingDistance n (Land x) (Land y) = hypotenuse n (abs (x-y))

fullWalkingDistance :: Int -> Measures -> Int
fullWalkingDistance n []     = 0
fullWalkingDistance n [x]    = 0
fullWalkingDistance n (x1:x2:xs) = walkingDistance n x1 x2 + fullWalkingDistance n (x2:xs) 