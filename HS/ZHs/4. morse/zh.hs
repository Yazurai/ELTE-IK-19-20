import Data.Char
import Data.List

morseTab :: [(Char, String)]
morseTab =
  [('A',".-"),('B',"-..."),('C',"-.-."),('D',"-.."),('E',".")
  ,('F',"..-."),('G',"--."),('H',"...."),('I',".."),('J',".---")
  ,('K',"-.-"),('L',".-.."),('M',"--"),('N',"-."),('O',"---")
  ,('P',".--."),('Q',"--.-"),('R',".-."),('S',"..."),('T',"-")
  ,('U',"..-"),('V',"...-"),('W',".--"),('X',"-..-")
  ,('Y',"-.--"),('Z',"--..")
  ]

normalizeText :: String -> String
normalizeText txt = map (toUpper) $ filter (\x -> x `elem` ['A'..'z']) txt

charToCode :: [(Char,String)] -> Char -> String
charToCode morseTab c = snd((filter (\(ch,code) -> ch == c) morseTab)!!0)

encodeToWords :: String -> [String]
encodeToWords txt = map (charToCode morseTab) txt

encodeString :: String -> String
encodeString txt = foldl (++) [] (encodeToWords txt)

codeToChar :: [(a,String)] -> String -> a
codeToChar morseTab cd = fst((filter (\(ch,code) -> code == cd) morseTab)!!0)

decodeWords :: [String] -> String
decodeWords morse = map (codeToChar morseTab) morse

withShortestCodes :: [(Char,String)] -> [Char]
withShortestCodes codes = foldr (\(c,cd) acc -> if (length cd) == shortest then c:acc else acc) [] codes
  where
    shortest = getShortestCodeLength codes

getShortestCodeLength :: [(Char,String)] -> Int
getShortestCodeLength codes = foldl (\acc (c,cd) -> if acc > (length cd) then length cd else acc) (length (snd(codes!!0))) codes

getPossiblePrefixes :: [(Char,String)] -> String -> [(Char,String)]
getPossiblePrefixes _ "" = []
getPossiblePrefixes codes fullCd = filter (\(c,cd) -> compareStrings cd fullCd) codes

compareStrings :: String -> String -> Bool
compareStrings [] _ = True
compareStrings _ [] = False
compareStrings (x:xs) (y:ys) = (x == y) && (compareStrings xs ys)

decodeString :: String -> [String]
decodeString code = foldr (++) [] (map (\(c,cd) -> if (length cd) == (length code) then [[c]] else map (c:) (decodeString (drop (length cd) code))) possiblePrefix)
  where
    possiblePrefix = getPossiblePrefixes morseTab code
