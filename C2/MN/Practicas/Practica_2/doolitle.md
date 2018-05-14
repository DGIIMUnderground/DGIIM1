# Doolitle
```maxima
a: matrix(
 [0.1,0.2,0.3,0.4], 
 [0.2,0.9,1.2,1.5], 
 [0.3,1.6,2.9,3.5], 
 [0.4,2.3,4.6,6.5]
)

n:matrix_size(a)[1];
l:genmatrix( lambda([i,j] , if i=j then 1 else 0) , n , n);
u:genmatrix(lambda([i,j] , if i <= j then 1 else 0) , n , n);
doolitle(a):=
(
    for i:1 thru n do
    (
        for j:i thru n do
        (
            u[i,j]: a[i,j] - sum(u[k,j]*l[i,k] , k , 1 , i-1 )
        ),
        for j:i+1 thru n do 
        (
            l[j,i]: 1/u[i,i]*(a[j,i]-sum(u[k,i]*l[j,k], k , 1, i-1))
        )
        
    )
);
l;u;

```
