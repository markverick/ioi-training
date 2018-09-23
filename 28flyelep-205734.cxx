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
    memset(dp,-1,sizeof dp);
    dp[0][0]=0;
    dp[0][1]=0;
    dp[0][2]=0;
    dp[0][3]=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            for(k=3;k>=0;k--)
            {
                if(dp[i][k]==-1)
                    continue;
                if(h[j]<h[i])
                {
                    dp[j][k]=max(dp[j][k],dp[i][k]+1);
                }
                if(k<3&&h[j]>=h[i])
                    dp[j][k+1]=max(dp[j][k+1],dp[i][k]+1);
            }
        }
    }
    int mc=0;
    for(i=0;i<=3;i++)
    {
        //printf("%d\n",dp[n][i]);
        mc=max(mc,dp[n][i]);
    }
    printf("%d",mc);
}
