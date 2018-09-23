#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long dp[1135][1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,T,x,p;
	for(i=0;i<=80;i++)
        dp[i][0]=1,dp[0][i]=1;
	for(i=1;i<=80;i++)
	    for(j=1;j<=80;j++)
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
	scanf("%lld",&T);
	while(T--)
    {
        scanf("%lld %lld %lld",&n,&x,&p);
        printf("%lld\n",dp[x-n*p][n-1]);
    }

}
