#include<bits/stdc++.h>
int n;
long long fib[10000];

long long fx(int x)
{
    if(fib[x]>0)
    {
        return fib[x];
    }
    if (x==1)
    {
        return 1;
    }
    if(x==0)
    {
        return 1;
    }
    return fib[x]= fx(x-1)+fx(x-2);
}

int main()
{
    fib[0]=1;
    fib[1]=1;
    long long cot=0;

    int i,j,k;
    scanf("%d",&n);
    cot=fx(n);
    printf("%lld\n",cot);
}
