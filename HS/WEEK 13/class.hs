data Day = MONDAY | TUESDAY | WEDNESDAY | THURSDAY | FRIDAY | SATURDAY | SUNDAY

isFirstDayOfWeek :: Day -> Bool
isFirstDayOfWeek MONDAY = True
isFirstDayOfWeek _      = False

isWeekend :: Day -> Bool
isWeekend SATURDAY = True
isWeekend SUNDAY = True
isWeekend _      = False

type Minute = Int
type Hour = Int

data Time = T Hour Minute
    deriving Show

showTime :: Time -> String
showTime (T h m) = (show h) ++ "." ++ (show m)

eqTime :: Time -> Time -> Bool
eqTime (T h1 m1) (T h2 m2) = (h1==h2)&&(m1==m2)

isEarlier :: Time -> Time -> Bool
isEarlier (T h1 m1) (T h2 m2) = time1 < time2
    where
        time1 = h1*60+m1
        time2 = h2*60+m2

isBetween :: Time -> Time -> Time -> Bool
isBetween t1 t2 t3 = firstCase || secondCase
    where
        firstCase  = (isEarlier t1 t2) && (isEarlier t2 t3)
        secondCase = (isEarlier t3 t2) && (isEarlier t2 t1)

time :: Int -> Int -> Time
time h m
    |m<0||m>59 = error ("time: invalid minute: " ++ show(m))
    |h<0||h>23 = error ("time: invalid hour: " ++ show(h))
    |otherwise = T h m

data USTime = AM Hour Minute | PM Hour Minute deriving (Eq, Show) 

usTimeToTime :: USTime -> Time
usTimeToTime (AM h m) = T (h `mod` 12) m
usTimeToTime (PM h m) = T (12 + (h `mod` 12)) m

timeToUSTime :: Time -> USTime
timeToUSTime (T h m)
    |isEarlier (T 11 59) (T h m) = PM (convertedH (h-12)) m
    |otherwise                   = AM (convertedH h) m
    where
        convertedH x = if x `mod` 12 == 0 then 12 else x
