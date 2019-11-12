import Data.List

(rows,columns) = (7 :: Int, 6 :: Int)

winning = 4 :: Int

[red,yellow] = [0,1]

grid0 :: [[Int]]
grid0 = [[]
        ,[]
        ,[]
        ,[]
        ,[]
        ,[]]
grid1 :: [[Int]]
grid1 =
  [ [yellow,red,yellow,red]
  , []
  , [red,red,red,yellow]
  , []
  , []
  , [yellow,yellow,yellow,red,yellow,red,red]
  ]
grid2 :: [[Int]]
grid2 =
  [ [yellow,red,yellow,red]
  , [red,red,yellow,red]
  , [yellow,yellow,yellow]
  , [red,red,yellow,yellow]
  , [red]
  , [red,yellow,red,yellow]
  ]
grid3 :: [[Int]]
grid3 =
  [ [yellow,yellow, yellow]
  , [red,yellow,red]
  , [red,red,yellow,yellow]
  , [yellow,red,red,red]
  , [yellow,yellow,red,yellow]
  , [red,red,yellow,red]
  ]

emptyColumns :: [[Int]] -> Int
emptyColumns xs = length $ filter (==[]) xs

numOfPieces :: [[Int]] -> Int
numOfPieces xs = sum $ map (length) xs

emptyRows :: [[Int]] -> Int
emptyRows xs = length [ 1 | i <- [1..rows], length(filter (\x -> (length x) < i) xs) == columns]

putPiece :: Int -> Int -> [[Int]] -> [[Int]]
putPiece column color state = map (\x -> if x == column then if (length (state!!x)) < 7 then (state!!x)++[color] else state!!x else state!!x) [0..(columns-1)]

findStreak :: Int -> Int -> Int -> [Int] -> Bool
findStreak l n color list = 0 < (length [ 1 | i <- [0..(l - n)], n == (length $ filter (\x -> x == color) $ take n (snd(splitAt i list)))])

inAColumn :: Int -> Int -> [[Int]] -> Bool
inAColumn n color state = length([1 | i <- [0..(columns-1)], findStreak rows n color (state!!i)]) > 0

inARow :: Int -> Int -> [[Int]] -> Bool
inARow n color state = length([1 | i <- [0..(rows-1)], findStreak rows n color [if(length (state!!j) > i) then state!!j!!i else 3 | j <- [0..(columns-1)]]]) > 0

getDiagonal :: Int -> Int -> Bool -> [[Int]] -> [Int]
getDiagonal col row dir state
    |dir       = if (state!!)
    |otherwise = 

inADiagonal :: Int -> Int -> [[Int]] -> Bool
inADiagonal n color state = 
