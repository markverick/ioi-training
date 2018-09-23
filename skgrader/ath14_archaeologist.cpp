#include<bits/stdc++.h>
using namespace std;
int d[333][333],r,c,maps[333][333],dp[305][305][305];
inline void add(int x,int a,int b)
{
    int i,j,mc=-1000000000;
    if(a==b)
    {
        for(i=-1;i<=1;i++)
            for(j=-1;j<=1;j++)
                mc=max(mc,dp[x-1][a+i][b+j]);
        dp[x][a][b]=mc+maps[x][a];
    }
    else
    {
        for(i=-1;i<=1;i++)
            for(j=-1;j<=1;j++)
                mc=max(mc,dp[x-1][a+i][b+j]);
        dp[x][a][b]=mc+maps[x][a]+maps[x][b];
    }
}
int main()
{
    int i,j,k,w,x,y,t;
    scanf("%d %d",&r,&c);
    for(i=0;i<=r+1;i++)
        for(j=0;j<=c+1;j++)
            for(k=0;k<=c+1;k++)
                dp[i][j][k]=-1000000000,dp[i][j][k]=-1000000000;
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            scanf("%d",&maps[i][j]);
    int mc=-1000000000;
    for(i=1;i<=c;i++)
        for(j=1;j<=c;j++)
            if(i==j)
                dp[1][i][j]=maps[1][i];
            else
                dp[1][i][j]=maps[1][i]+maps[1][j];
    for(i=2;i<=r;i++)
        for(j=1;j<=c;j++)
            for(k=1;k<=c;k++)
                add(i,j,k);
    for(i=1;i<=c;i++)
        mc=max(mc,dp[r][i][i]);
    printf("%d",mc);
}
