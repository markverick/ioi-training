#include<bits/stdc++.h>
using namespace std;
long long dp[90135],a[135];
int main()
{
    long long n,i,j,k,sum=0,T;
    scanf("%lld",&T);
    while(T--)
    {
        memset(dp,0,sizeof dp);
        sum=0;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        dp[0]=1;
        for(i=1;i<=n;i++)
        {
            for(k=45001;k>=0;k--)
            {
                dp[k+a[i]]|=(dp[k]<<1ll);
            }
        }
        long long mn=1000000000000000000,x,y;
        for(i=45001;i>=0;i--)
        {
            if(((1ll<<(n/2))|dp[i])==dp[i])
            {
                if(mn>abs(sum-i-i))
                {
                    mn=abs(sum-i-i);
                    x=i;y=sum-i;
                }
            }
        }
        if(x>y)swap(x,y);
        printf("%lld %lld\n\n",x,y);
    }
}
