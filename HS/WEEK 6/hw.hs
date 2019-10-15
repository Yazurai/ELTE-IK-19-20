table :: [(Char, Char)]
table = zip table1 table2
    where 
        table1 = ' ':['a'..'z']
        table2 = ' ':['d'..'z'] ++ ['a'..'c']

--You can see that sometimes list comprehensions are more succint than using higher order functions
shift :: [(Char, Char)] -> Char -> Char
shift table c = [coded | (char,coded) <- table, c == char]!!0
--            = snd $ (filter (\(char,code) -> c == char) table)!!0

encrypt :: [(Char, Char)] -> String -> String
encrypt table xs = [shift table x | x <- xs]
--               = map (shift table) xs