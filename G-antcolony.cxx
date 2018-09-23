#include<bits/stdc++.h>
#define MI 1000000000000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long pa[100135],p[20][100135],d[20][100135],h[100135];
vector<pair<long long,long long> > adj[100135];
vector<tuple<long long,long long,long long> > e;
long long Find(long long x)
{
	if(x==pa[x])return x;
	return pa[x]=Find(pa[x]);
}
void Union(long long x,long long y)
{
	x=Find(x);
	y=Find(y);
	pa[x]=y;
}
void dfs(long long idx,long long hi)
{
	long long i,j;
	h[idx]=hi;
	pair<long long,long long> ad;
	for(i=0;i<adj[idx].size();i++)
	{
		ad=adj[idx][i];
		if(ad.X==p[0][idx])continue;
		p[0][ad.X]=idx;
		d[0][ad.X]=ad.Y;
		for(j=1;j<=18;j++)
			p[j][ad.X]=p[j-1][p[j-1][ad.X]],d[j][ad.X]=d[j-1][ad.X]+d[j-1][p[j-1][ad.X]];
		dfs(ad.X,hi+1);
	}
}
long long lca(long long x,long long y)
{
	long long mc=0,i,sm=0;
	if(h[x]<h[y])swap(x,y);
	for(i=18;i>=0;i--)
	{
		if(h[p[i][x]]>=h[y])
		{
			sm+=d[i][x];
			x=p[i][x];
		}
	}
	if(x==y)return sm;
	for(i=18;i>=0;i--)
		if(p[i][x]!=p[i][y])
			sm+=d[i][x]+d[i][y],x=p[i][x],y=p[i][y];
	return sm+d[0][x]+d[0][y];
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,m,i,j,k,a,b,c,mn=MI,q;
	long long all=0;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++) pa[i]=i;
	for(i=1;i<=n-1;i++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		a++;b++;
		e.emplace_back(c,a,b);
	}
	sort(e.begin(),e.end());
	for(i=0;i<e.size();i++)
	{
		tie(c,a,b)=e[i];
		if(Find(a)!=Find(b))
		{
			adj[a].emplace_back(b,c);
			adj[b].emplace_back(a,c);
			Union(a,b);
			all+=c;
			e[i]=MT(0,0,0);
		}
	}
	dfs(1,1);
	while(m--)
	{
		scanf("%lld %lld",&a,&b);a++;b++;
		printf("%lld\n",lca(a,b));
	}
}