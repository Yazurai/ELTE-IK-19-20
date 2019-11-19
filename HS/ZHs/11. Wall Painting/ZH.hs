import Data.List

testWall :: [[Int]]
testWall =
    [[0,0,0]
    ,[5,5,5]
    ,[1,2,1]]

monochromeWall :: Int -> Int -> [[Int]]
monochromeWall c n = take n (repeat (take n (repeat c)))

invertARow :: [Int] -> [Int]
invertARow = map (9-)

invert :: [[Int]] -> [[Int]]
invert = map invertARow

numberOfInvalidColours :: [[Int]] -> Int
numberOfInvalidColours xs = length $ filter (\x -> x < 0 || 9 < x) total
    where 
        total = foldl (++) [] xs

changeInvalidColours :: [[Int]] -> [[Int]]
changeInvalidColours xs = [ map (\y -> if y < 0 || 9 < y then 0 else y) x | x <- xs]

xPatternedWall :: Int -> Int -> Int -> [[Int]]
xPatternedWall bgc fgc n = [ [ if x==y || x+y==n+1 then fgc else bgc | x <- [1..n] ] | y <- [1..n] ]

mixWallPatterns :: (Int -> Int -> Int) -> [[Int]] -> [[Int]] -> [[Int]]
mixWallPatterns mix xs ys = [ [ mix (xs!!y!!x) (ys!!y!!x) | x <- [0..newN] ] | y <- [0..newN] ]
    where
        newN = min (length xs) (length ys) - 1

colorStatistics :: [[Int]] -> [(Int,Int)]
colorStatistics x = map (\x -> (x!!0,length) ) $ group.sort $ foldl (++) [] xs