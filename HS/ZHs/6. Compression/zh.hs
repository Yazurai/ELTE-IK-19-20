import Data.Function
import Data.List 

type CodeTab = [TabEntry]
type TabEntry = (Char, Code)
type Code = [Bit]
data Bit = Zero | One
    deriving (Eq,Show,Data,Typeable)

getFrequencies :: String -> [(Int, Char)]
getFrequencies xs = occurenceMaps
    where
        occurenceMaps = filter (\(x,c) -> x > 0) (map (\x -> (length $ filter (==x) xs,x) ) ['!'..'z'])

