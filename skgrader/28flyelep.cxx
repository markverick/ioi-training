#include<bits/stdc++.h>
using namespace std;
int h[10135];
int dp[10135][5];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    h[0]=0;
    for(i=0;i<=10000;i++)
        for(j=0;j<=3;j++)
            dp[i][j]=-1000000000;
//    for(i=0;i<=10000;i++)
    dp[0][0]=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(h[j]<h[i])
            {
                for(k=3;k>=0;k--)
                    dp[j][k]=max(dp[j][k],dp[i][k]+1);
            }
            else
            {
                for(k=2;k>=0;k--)
                    dp[j][k+1]=max(dp[j][k+1],dp[i][k]+1);
            }
        }
    }
    int mc=0;
    for(i=0;i<=3;i++)
        for(j=0;j<=n;j++)
        mc=max(mc,dp[j][i]);
    printf("%d",mc);
}
