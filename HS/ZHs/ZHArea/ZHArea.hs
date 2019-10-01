type Path = String

path0, path1, path2 :: Path
path0 = "urrd"
path1 = "urdl"
path2 = "uurrddll"
path3 = "ururdrdldlul"

mirror :: Path -> Path
mirror path = map (swap) (reverse path)
    where
        swap 'u' = 'd'
        swap 'd' = 'u'
        swap 'l' = 'r'
        swap 'r' = 'l'

isClosed :: Path -> Bool
isClosed path = horizontal && vertical
    where
        horizontal = (getCount 'l') == (getCount 'r')
        vertical = (getCount 'u') == (getCount 'd')
        getCount c = (length(filter(==c)path))

points :: Path -> (Int, Int) -> [(Int, Int)]
points [] pos = [pos]
points (p:ps) (x,y)
    |p == 'u' = (x,y):(points ps (x,y+1)) 
    |p == 'd' = (x,y):(points ps (x,y-1)) 
    |p == 'r' = (x,y):(points ps (x+1,y)) 
    |p == 'l' = (x,y):(points ps (x-1,y)) 

area :: Path -> Int
area path = sum [calc i | i <- [0..(n-1)]]
    where
        calc n = (ys!!n)*((xs!!(n+1)) - (xs!!n))
        n = length path
        xs = [x | (x,_) <- pos]
        ys = [y | (_,y) <- pos]
        pos = points path (0,0)

isInside :: (Int, Int) -> Path -> Int
isInside (x,y) path = above `min` below `min` left `min` right
    where
        pos = points path (0,0)
        sameY = filter ((==y).snd) pos
        sameX = filter ((==x).fst) pos
        above = length(filter ((>x).fst) sameY) 
        below = length(filter ((<x).fst) sameY) 
        left  = length(filter ((>y).snd) sameX) 
        right = length(filter ((<y).snd) sameX) 