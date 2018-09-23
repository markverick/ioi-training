#include<bits/stdc++.h>
using namespace std;
long long a[1135];
long long dp[1135][1135];
int main()
{
    long long n,m,i,j,mc=0;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        memset(dp,0,sizeof dp);
        mc=0;
        if(n==0&&m==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        dp[0][0]=1;
        for(i=1;i<=n;i++)
        {
            dp[1][i]=dp[1][i-1]+a[i];
            dp[1][i]%=m;
            dp[i][i]=dp[i-1][i-1]*a[i];
            dp[i][i]%=m;
            //printf("%lld\n",dp[1][i]);
        }
        for(i=2;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1]+dp[i-1][j-1]*a[j];
                dp[i][j]%=m;
            }
        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<=n;j++)
//            {
////            mc=max(mc,dp[i][n]);
//                printf("%2d ",dp[i][j]);
//            }
//            printf("\n");
//        }
        for(i=1;i<=n;i++)
        {
            mc=max(mc,dp[i][n]);
        }
        printf("%lld\n",mc);
    }
}
