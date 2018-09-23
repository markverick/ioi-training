#include<bits/stdc++.h>
//ath14_turtlesage
#define MI 10000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<long long> adj[100135];
long long jum[100135],ban[100135],w[100135],MC[100135];
void mx(pair<long long,long long> &a,long long b)
{
	if(b>a.X)
		swap(a.X,a.Y),a.X=b;
	else if(b>a.Y) a.Y=b;
}
long long dp(long long idx,long long p)
{
	if(jum[idx]>=-MI*2)return jum[idx];
	long long i;
	pair<long long,long long> mc;
	if(ban[idx])mc=MP(0,-MI);
	else mc=MP(-MI,-MI);
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p)continue;
		mx(mc,dp(adj[idx][i],idx));
	}
	MC[idx]=mc.X+mc.Y+w[idx];
	// printf("!%lld <- %lld -> %lld\n",mc.X,w[idx],mc.Y);
	return jum[idx]=mc.X+w[idx];
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long T,n,i,j,k,a,b,mc=0;
	scanf("%lld",&T);
	while(T--)
	{
		mc=-MI*2;
		memset(ban,0,sizeof ban);
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
			adj[i].clear(),jum[i]=-MI*2-1,MC[i]=-MI;
		for(i=1;i<n;i++)
		{
			scanf("%lld %lld",&a,&b);
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		for(i=1;i<=n;i++)
			scanf("%lld",&w[i]);
		for(i=1;i<=n;i++)
			scanf("%lld",&ban[i]);
		dp(1,0);
		for(i=1;i<=n;i++)
		{
			if(ban[i])
			{
				mc=max(mc,dp(i,0));
			}
			mc=max(mc,MC[i]);
		}
		if(mc>0)
			printf("%lld\n",mc);
		else
			printf("Stay Home\n");
	}
}