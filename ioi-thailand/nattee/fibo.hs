main :: IO ()
main = (readLn >>= (\n -> putStrLn (show (fibonacci n))))
fibonacci :: Integer -> Integer
fibonacci 1 = 1
fibonacci 2 = 1
fibonacci n = fibonacci (n-1) + fibonacci (n-2)
