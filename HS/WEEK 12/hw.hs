import Data.List

rook :: (Int, Int) -> [(Int, Int)]
rook (x,y) = [ (a,b) | a <- [0..7], b <- [0..7], (a == x || b == y) && (a,b) /= (x,y)]

knight :: (Int, Int) -> [(Int, Int)]
knight (x,y) = [ (a,b) | a <- [0..7], b <- [0..7], abs(a-x) + abs(b-y) == 3 && a /= x && b /= y]

attacks :: ((Int, Int) -> [(Int, Int)]) -> (Int, Int) -> [(Int, Int)] -> Bool
attacks f pos state = any (`elem` state) (f pos)

moves :: ((Int, Int) -> [(Int, Int)]) -> (Int, Int) -> [(Int, Int)] -> [[(Int, Int)]]
moves f pos state = map (:filter (/=pos) state) $ filter (\x -> not(x `elem` state)) $ f pos

movesAux :: (Int, Int) -> (Int, Int) -> [(Int, Int)] -> [(Int, Int)]
movesAux x pos (y:ys)
 -- | x elem (y:ys) = []
  | pos == y        = x:ys
  | otherwise       = y:movesAux x pos ys

movesAux2 :: [(Int, Int)] -> (Int, Int) -> [(Int, Int)] -> [[(Int, Int)]]
movesAux2 [] _ _ = []
movesAux2 (x:xs) pos table
  | x `elem` table = movesAux2 xs pos table 
  | otherwise      = movesAux x pos table : movesAux2 xs pos table

moves' :: ((Int, Int) -> [(Int, Int)]) -> (Int, Int) -> [(Int, Int)] -> [[(Int, Int)]]
moves' p pos table = movesAux2 (p pos) pos table