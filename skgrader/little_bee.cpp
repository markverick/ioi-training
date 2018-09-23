#include<bits/stdc++.h>
int a;
long long fib[120000];

long long fx(int x)
{
    if(fib[x]>=0)
    {
        return fib[x];
    }
    if (x<=1)
    {
        return 1;
    }

    return fib[x]= fx(x-1)+fx(x-2);

}

int main()
{
    long long cot=0;
    int m;
    int a,b;
    int i,j,k;
    for(i=0;i<120000;i++)
    {
        fib[i]=-1;
    }
    /*for(i=0;i<99999;i++)
    {
        fx(i);
    }*/
    scanf("%d %d",&a,&b);
    printf("%lld",fx(b-a));
}

