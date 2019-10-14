isIdentifierStart :: Char -> Bool
isIdentifierStart c = c `elem` identifierStarts
    where
        identifierStarts = '_':['a'..'z']

isIdentifierPart :: Char -> Bool
isIdentifierPart c = c `elem` identifierParts
    where
        identifierParts = ['A'..'Z'] ++ ['a'..'z'] ++ ['0'..'9'] ++ ['_']

isReserved :: String -> Bool
isReserved xs = xs `elem` reserves
    where
        reserves = ["if","then","else","module","import"]

isValid :: String -> Bool
isValid []     = False
isValid (x:xs) = startCorrect && partCorrect && reserveCorrect
    where
        startCorrect   = isIdentifierStart x
        partCorrect    = (length $ filter isIdentifierPart xs) == length xs
        reserveCorrect = not (isReserved (x:xs))

--There are multiple versions for partCorrect(brackets might be needed)
--partCorrect    = (length $ filter isIdentifierPart xs) == length xs
--partCorrect    = length [x | x <- xs, isIdentifierPart x] == length xs
--partCorrect    = all isIdentifierPart xs
        