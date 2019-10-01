-- 5.GYAKORLAT
import Data.List

divisors :: Int -> [Int]
divisors n = [x | x <- [1..n], n `mod` x == 0]

isPrime :: Int -> Bool
isPrime n = length(divisors n) == 2

primes = [x | x <- [1..], isPrime x]

dominoes = [(a,b) | a <- [0..6], b <- [0..6], a >= b]

--Ez nincs a korrekt formatumban
allPairs = [(a,b) | a <- [0..], b <- [0..]]

alphabet = zip [0..25] ['a'..'z']

everyThird = [c | (n,c) <- alphabet, n `mod` 3 == 2]

courses =
    [ ("Programozasi nyelvek II.", [("Horvath", "Istvan", "BDE91E"), ("Fodros", "Aniko", "DDA3KX")])
    , ("Imperativ programozas", [("Nemeth", "Eniko", "ALX1K0"), ("Horvath", "Istvan", "BDE91E")])
    , ("Funkcionalis programozas", [("Kiss", "Elemer", "ABCDE6"), ("Nagy", "Jakab", "CDE560")])]

students = [cd |(courseName, stds) <- courses, (_,_,cd) <- stds, courseName == "Funkcionalis programozas"]

getStudentIDs :: String -> [String]
getStudentIDs name = [cd |(courseName, stds) <- courses, (_,_,cd) <- stds, courseName == name]

days = [31,28,31,30,31,30,31,31,30,31,30,31]
calendar = [(month, day) | month <- [1..12], day <- [1..days!!(month-1)]]

compress :: String -> [(Int, Char)]
compress str = [(length(grp), grp!!0) | grp <- group str]

decompress :: [(Int, Char)] -> String
decompress code = concat [replicate count c |(count, c) <- code]