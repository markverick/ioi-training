
#include<bits/stdc++.h>
long long fib[1500][1500];

long long fx(int x,int y)
{
    if(fib[x][y]>=0)
    {
        return fib[x][y];
    }
    if (x<=1&&y<=1)
    {
        return 1;
    }
    if(x<=1)
    {
        return fib[x][y]= fx(x,y-1)%558829;
    }
    else if(y<=1)
    {
        return fib[x][y]= fx(x-1,y)%558829;
    }
    else
    {
        return fib[x][y]= (fx(x-1,y)+fx(x,y-1))%558829;
    }


}

int main()
{
    long long cot=0;
    int m;
    int a,b;
    int i,j,k;
    for(i=0;i<1500;i++)
    {
        for(j=0;j<1500;j++)
        {
            fib[i][j]=-1;
        }
    }
    /*for(i=0;i<99999;i++)
    {
        fx(i);
    }*/
    scanf("%d %d",&a,&b);
    printf("%lld",fx(a+1,b+1));
}

