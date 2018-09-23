#include<bits/stdc++.h>
#define MI 1000000000
#define M 1000000007
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,m,jum[105][105];
long long dp(long long x,long long y)
{
	if(jum[x][y]>=0)
		return jum[x][y];
	long long i,j,sm=1;
	for(i=x+1;i<=n;i++)
	{
		for(j=y+1;j<=n;j++)
		{
			sm+=dp(i,j)*(min(m,i-x-1)+min(m,j-y-1));
			sm%=M;
		}
	}
	return jum[x][y]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,sm=0;
	memset(jum,-1,sizeof jum);
	scanf("%lld %lld",&n,&m);
	k=dp(0,0);
	k--;
	if(k<0)
		k+=M;
	printf("%lld",k);
}