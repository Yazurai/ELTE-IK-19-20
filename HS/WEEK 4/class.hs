--3. GYAKORLAT

and' :: Bool -> Bool -> Bool
and' True True = True
and' _ _ = False

or' :: Bool -> Bool -> Bool
or' False False = False
or' _ _ = True

xor :: Bool -> Bool -> Bool
xor True False = True
xor False True = True
xor _ _ = False

add2 :: Int -> Int -> (Int, Int)
add2 a b
    | 0 <= a && a < 2 && 0 <= b && b < 2 = (carryOut,sum)
    where
        sum = (a + b) `div` 2
        carryOut = (a + b) `mod` 2

paren :: Char -> Char -> Bool
paren '(' ')' = True
paren '{' '}' = True
paren '[' ']' = True
paren _ _ = False

calc :: (Int, Char, Int) -> Int
calc (a, '+', b) = a + b
calc (a, '-', b) = a - b
calc (a, '*', b) = a * b
calc (a, '/', b) = a `div` b
calc _ = 0

isSpace :: Char -> Bool
isSpace ' ' = True
isSpace _ = False