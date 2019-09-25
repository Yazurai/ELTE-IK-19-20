shift :: (Int, Int) -> Int -> (Int, Int)
shift (h, m1) m2 = (newH, newM)
    where 
        newH = (h + (m1 + m2)`div`(60))`mod`24
        newM = (m1 + m2)`mod`(60)

isEarlier :: (Int, Int) -> (Int, Int) -> Bool
isEarlier (h1, m1) (h2, m2) = total1 < total2 
    where 
        total1 = h1*60+m1
        total2 = h2*60+m2

createEvent :: (Int, Int) -> Int -> String -> ((Int, Int), (Int, Int), String)
createEvent start t desc = (start, finish, desc)
    where
        finish = shift start t

