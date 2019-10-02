nand :: Bool -> Bool -> Bool
nand True True = False
nand _ _ = True

onAxis :: (Int, Int) -> Bool
onAxis (0,_) = True
onAxis (_,0) = True
onAxis _ = False

punctuation :: Char -> Bool
punctuation '?' = True
punctuation '!' = True
punctuation '.' = True
punctuation _ = False