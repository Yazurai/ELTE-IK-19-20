data Privilege = Unprivileged | Admin deriving (Eq)

type Username = String
type Db = [(String, String, Privilege)] 

data Cookie = LoggedOut | LoggedIn Username Privilege deriving (Eq)

db = [("dumbledore","abracadabra",Unprivileged), ("root", "secret", Admin), ("bela", "korte", Unprivileged)] 

register :: String -> String -> Cookie -> Db -> Db
register name password (LoggedIn _ Admin) db = (name, password, Unprivileged) : db
register _ _ _ db = db

getUser :: String -> Db -> Maybe (String,Privilege)
getUser name db
    |(length usersFound) > 0 = Just (pass,priv)
    |otherwise               = Nothing
    where
        (_, pass, priv) = head usersFound 
        usersFound      = filter (\(n,_,_) -> n == name) db

login :: String -> String -> Db -> Cookie
login name password db
    |correctLogin = LoggedIn name priv
    |otherwise    = LoggedOut
    where
        (correctLogin,pass,priv) = case userData of Just (pass,priv) -> (pass == password,pass,priv)
                                                    Nothing          -> (False,"",Unprivileged)
        userData = getUser name db

passwd :: String -> Cookie -> Db -> Db
passwd _ LoggedOut db = db
passwd newPass (LoggedIn username _) db = map (\(name, pass, priv) -> if username == name then (name, newPass, priv) else (name, pass, priv)) db

delete :: String -> Cookie -> Db -> Db
delete username (LoggedIn adminName Admin) [] = []
delete username (LoggedIn adminName Admin) ((name, pass, priv):db)
    |name == username = delete username (LoggedIn adminName Admin) db
    |otherwise        = (name, pass, priv) : (delete username (LoggedIn adminName Admin) db)
delete _ _ db = db

users :: Db -> [String]
users db = map (\(name, _, _) -> name) db