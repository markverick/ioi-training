fibo n = if n == 1 then 1
    else if(n==2) then 1
    else fibo (n-1) + fibo (n-2)
fibo2 1 = 1
fibo2 2 = 1
fibo2 n = fibo2 (n-1) + fibo2 (n-2)

len [] = 0
len (_:xs) = 1 + len xs

sum0 [] = 0
sum0 (x:xs) = x + sum0 xs

ll 0 = []
ll n = n:(ll (n-1))
myappend x [] = [x]
myappend x (y:ys) = y:(myappend x ys)

--myconcat xs [] = xs
----myconcat xs (y:ys) = myconcat (myappend y xs) ys
--myconcat xs (y:ys) = myconcat xxs ys
--    where xxs = myappend y xs
rev0 [] ys = ys
rev0 (x:xs) ys = rev0 xs (x:ys)

rev xs = rev0 xs []


myconcat0 [] ys = ys
myconcat0 (x:xs) ys = myconcat0 xs (x:ys)
myconcat xs ys = myconcat0 (rev xs) ys

insert [] y = [y]
insert (x:xs) y = if y < x then y:x:xs
                else x:(insert xs y)

isort [] = []
isort (y:ys) = insert (isort ys) y
--myconcat x []=[]
--myconcat x y = myconcat y:(tail x) (x:_)
