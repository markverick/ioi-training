#include<bits/stdc++.h>
#define MI 1000000000000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,m,a[333][333],jum[333][333];
long long dp(long long idx,long long num)
{
	if(jum[idx][num]>=0)return jum[idx][num];
	if(idx==n+1)
	{
		return 0;
	}
	long long mn=MI,sm=0,i;
	if(num>0)
		mn=min(mn,dp(idx+1,num-1));
	for(i=1;i<=m;i++)
	{
		sm+=a[idx][i];
		if(num-1+i>n)break;
		mn=min(mn,dp(idx+1,num-1+i)+sm+i*i);
	}
	return jum[idx][num]=mn;
}
int main()
{
	// freopen("out1.txt","w",stdout);
	// freopen("in1.txt","r",stdin);
	long long T,t,i,j,k;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		memset(jum,-1,sizeof jum);
		scanf("%lld %lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				scanf("%lld",&a[i][j]);
			sort(&a[i][1],&a[i][m+1]);
		}
		printf("Case #%lld: %lld\n",t,dp(1,0));
	}	
}