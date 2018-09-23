#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100135];
long long dp[100135];
int main()
{
    long long i,j,tmp;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(i=1;i<=n+1;i++)
        dp[i]=1000000000;
    for(i=0;i<=n;i++)
    {
        for(j=i+1;j<=min(i+m,n+1);j++)
        {
            tmp=dp[i]+a[j]+(j-i)*(j-i);
            if(tmp<dp[j])
            {
                dp[j]=tmp;
            }
        }
    }
    printf("%lld",dp[n+1]);
}
