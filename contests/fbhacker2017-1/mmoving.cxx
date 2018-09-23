#include<bits/stdc++.h>
#define MI 10000000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,m,o;
long long adj[135][135],st[5135],ed[5135],jum[135][3];
long long dp(long long idx,long long db)
{
	if(jum[idx][db]>=0)return jum[idx][db];
	if(idx==o)
	{
		if(db==0)
			return adj[st[idx]][ed[idx]];
		return adj[st[idx]][ed[idx-1]]+adj[ed[idx-1]][ed[idx]];
	}
	if(db==0)
	{
		return jum[idx][db]=min(dp(idx+1,0)+adj[st[idx]][ed[idx]]+adj[ed[idx]][st[idx+1]],
				   dp(idx+1,1)+adj[st[idx]][st[idx+1]]);
	}
	else
	{
		return jum[idx][db]=min(dp(idx+1,1)+adj[st[idx]][ed[idx-1]]+adj[ed[idx-1]][st[idx+1]],
				   dp(idx+1,0)+adj[st[idx]][ed[idx-1]]+adj[ed[idx-1]][ed[idx]]+adj[ed[idx]][st[idx+1]]);
	}
}
int main()
{
	freopen("out2.txt","w",stdout);
	freopen("in2.txt","r",stdin);
	long long T,t,i,j,k,a,b,c;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%lld %lld %lld",&n,&m,&o);
		memset(jum,-1,sizeof jum);
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				adj[i][j]=MI;
		for(i=1;i<=m;i++)
		{
			scanf("%lld %lld %lld",&a,&b,&c);
			adj[a][b]=min(adj[a][b],c);
			adj[b][a]=min(adj[b][a],c);
		}
		for(i=1;i<=n;i++)
			adj[i][i]=0;
		for(k=1;k<=n;k++)
			for(i=1;i<=n;i++)
				for(j=1;j<=n;j++)
					adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
		for(i=1;i<=o;i++)
			scanf("%lld %lld",&st[i],&ed[i]);
		k=dp(1,0)+adj[1][st[1]];
		if(k>=MI)
			k=-1;
		printf("Case #%lld: %lld\n",t,k);

	}
}