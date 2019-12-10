data Month = Jan | Feb | Mar | Apr | May | Jun | Jul | Aug | Sep | Oct | Nov | Dec
    deriving (Show, Eq)

type Year = Int

months :: [Month]
months = [Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec]

gapYear :: [Int]
gapYear = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

normalYear :: [Int]
normalYear = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

numberOfDays' :: Year -> Month -> Int
numberOfDays' y m
    |(y `mod` 4 /= 0) || (y `mod` 100 == 0 && y `mod` 400 /= 0) = [day | (mon,day) <- (zip months gapYear), mon == m]!!0
    |otherwise                                                  = [day | (mon,day) <- (zip months normalYear), mon == m]!!0

numberOfDays :: Year -> Month -> Int
numberOfDays y Feb
    |(y `mod` 4 /= 0) || (y `mod` 100 == 0 && y `mod` 400 /= 0) = 28
    |otherwise                                                  = 29
numberOfDays _ Apr = 30
numberOfDays _ Jun = 30
numberOfDays _ Sep = 30
numberOfDays _ Nov = 30
numberOfDays _ _ = 31

