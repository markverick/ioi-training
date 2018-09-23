#include<bits/stdc++.h>
int n;
long long fib[120000];

long long fx(int x)
{
    if(fib[x]>=0)
    {
        return fib[x];
    }
    if (x==1)
    {
        return 2;
    }
    if(x==2)
    {
        return 4;
    }
    return fib[x]= (fx(x-1)+fx(x-2))%2133134135;

}

int main()
{
    fib[0]=1;
    fib[1]=2;
    fib[2]=4;
    long long cot=0;
    int m;

    scanf("%d",&m);
    int i,j,k;
    for(i=0;i<120000;i++)
    {
        fib[i]=-1;
    }
    for(i=0;i<99999;i++)
    {
        fx(i);
    }

    for(i=0;i<m;i++){
        scanf("%d",&n);
        if(n!=0){
            cot=fx(n);
            printf("%lld\n",cot);
        }
        else{
            printf("0\n");
        }


    }

}

