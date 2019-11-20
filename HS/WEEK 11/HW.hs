type Movie = (String, Double, String)

movies :: [Movie]
movies = [ ("Green Book", 8.3, "Peter Farrelly")
         , ("Inception", 8.8, "Christopher Nolan")
         , ("Incredibles 2", 7.7, "Brad Bird")
         , ("The Dark Knight", 9.0, "Christopher Nolan")
         ]

imdbAtLeast :: Double -> Movie -> Bool
imdbAtLeast x (_, y, _) = x <= y

director :: String -> Movie -> Bool
director name (_, _, prod) = name == prod

and_ :: (Movie -> Bool) -> (Movie -> Bool) -> Movie -> Bool
and_ f1 f2 mov = (f1 mov) && (f2 mov) 

or_ :: (Movie -> Bool) -> (Movie -> Bool) -> Movie -> Bool
or_ f1 f2 mov = (f1 mov) || (f2 mov)

search :: (Movie -> Bool) -> [Movie] -> [Movie]
search f = filter f 