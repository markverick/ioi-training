#include<bits/stdc++.h>
using namespace std;
int a[13],n,m;
int dp[1000005];
int main()
{
    int i,j,k,mn;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
//        memset(dp,0,sizeof dp);
        for(i=1;i<=m;i++)
        {
            scanf("%d",&a[i]);
        }
        dp[0]=0;
        for(i=1;i<=n;i++)
        {
            mn=1;
            for(j=1;j<=m;j++)
            {
                if(i-a[j]>=0)
                {
                    mn=min(mn,dp[i-a[j]]);
                }
            }
            dp[i]=1-mn;
        }
        if(dp[n])
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
}
