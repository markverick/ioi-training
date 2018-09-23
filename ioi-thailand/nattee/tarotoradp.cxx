#include<bits/stdc++.h>
#define MI 100000000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long dp[3][235],a[100135],b[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,T,m,mn=0,md;
    scanf("%lld",&T);
    while(T--)
    {
        mn=MI;
        scanf("%lld %lld",&n,&m);
        md=m+1;
        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&a[i],&b[i]);
        }
        for(i=0;i<=1;i++)
            for(j=0;j<=md*2;j++)
                dp[i][j]=MI;
        dp[0][md]=0;
        for(i=1;i<=n;i++)
        {
///            for(abs(n-i-i)<=m
            for(j=md-m;j<=md+m;j++)
            {
                dp[i%2][j]=min(dp[(i+1)%2][j-1]+a[i],dp[(i+1)%2][j+1]+b[i]);
            }
        }
//        for(i=1;i<=n;i++)
//        {
//            for(j=1;j<md;j++)
//                printf("%5d ",dp[i][j]);
//            printf("%5d ",dp[i][md]);
//            for(j=md+1;j<=md*2;j++)
//                printf("%5d ",dp[i][j]);
//            printf("\n");
//        }
        mn=MI;
        for(j=md-m;j<=md+m;j++)
        {
            mn=min(mn,dp[n%2][j]);
        }
        printf("%lld\n",mn);
    }
}
