import Data.Function
import Data.List 

type CodeTab = [TabEntry]
type TabEntry = (Char, Code)
type Code = [Bit]
data Bit = Zero | One
    deriving (Eq,Show,Data,Typeable)

getFrequencies :: String -> [(Int, Char)]
getFrequencies xs = sortBy (compare `on` snd) counted
    where
        counted = map (\y -> foldl () 0 xs)
        all = sortUniq `on` (snd xs)

