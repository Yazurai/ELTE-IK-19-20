--align :: Int -> String -> String
--align n xs = take (n - length xs) (cycle " ") ++ xs

takeWord :: String -> String
takeWord ""       = ""
takeWord (' ':xs) = ""
takeWord (x:xs)   = x:(takeWord xs)

dropWord :: String -> String
dropWord ""       = ""
dropWord (' ':xs) = ' ':xs
dropWord (x:xs)   = dropWord xs

words' :: String -> [String]
words' "" = []
words' (' ':xs) = words' xs
words' xs = (takeWord xs):(words' (dropWord xs))