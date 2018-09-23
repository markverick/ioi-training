#include<bits/stdc++.h>
using namespace std;
int dp[20135];
int main()
{
    int n,m,i,j,k;
    dp[1]=1;
    scanf("%d %d %d",&n,&m,&k);
    for(i=0;i<=n;i++)
    {
        dp[i]++;
        for(j=1;j<=k;j++)
        {
            if(i-j>=0)
                dp[i]+=dp[i-j];
        }
        for(j=1;j<=k;j++)
        {
            dp[i]+=dp[i+j];
            dp[i]%=1000007;
        }
        dp[i+j]%=1000007;
    }
    printf("%d",dp[n]);
}
