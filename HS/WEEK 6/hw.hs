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


--2. Eltolás
--Írj egy shift nevű függvényt, mely egy karakter eltolt párját keresi ki egy táblázatból! Feltesszük, hogy a karakter megtalálható a táblázatban.

--Add meg a függvény típusát is!

--Az alábbi tesztesetek közül mindegyiknek True-t kell adnia:

--shift table ' ' == ' '
--shift table 'a' == 'd'
--shift table 'b' == 'e'
shift table 'x' == 'a'
shift table 'y' == 'b'
shift [('b', 'g'), ('c', 'h'), ('a', 'f')] 'a' == 'f'
shift [('b', 'g'), ('c', 'h'), ('a', 'f')] 'b' == 'g'



3. Titkosítás
Nem maradt más hátra, mint egész szövegek titkosítása. Ehhez definiáld az encrypt függvényt, melynek paramétere a táblázat és a titkosítandó szöveg lesz!

Az alábbi tesztesetek közül mindegyiknek True-t kell adnia:

encrypt table "abcd"           == "defg"
encrypt table "hello"          == "khoor"
encrypt table "haskell is fun" == "kdvnhoo lv ixq" 
encrypt table "wxyz"           == "zabc"
encrypt table ""               == ""
encrypt [('p', 'p'), ('g', 'n'), ('u', 'a')] "pug" == "pan"