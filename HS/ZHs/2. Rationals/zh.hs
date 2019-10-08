nextRational :: Rational -> Rational
nextRational x = 1/(2*y+1-x)
  where
    y = fromIntegral(floor x)

