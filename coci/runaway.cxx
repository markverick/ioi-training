#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,m,a,b;
vector<pair<long long,long long> > adj[200135];
long long p[200135],l[200135],qs[200135],out[200135];
vector<pair<long long,long long> > v;
vector<pair<long long,long long> > ::iterator it;
void dfs(long long idx)
{
	long long i;
	if(v.empty())v.emplace_back(0,idx);
	else
		v.emplace_back(v.back().X+l[idx],idx);
	qs[idx]++;
	it=lower_bound(v.begin(),v.end(),MP(v.back().X-m,0ll));
	qs[p[(*it).Y]]--;
	for(i=0;i<adj[idx].size();i++)
	{
		dfs(adj[idx][i].X);
	}
	v.pop_back();
}
long long dep(long long idx)
{
	long long i,sm=qs[idx];
	for(i=0;i<adj[idx].size();i++)
	{
		sm+=dep(adj[idx][i].X);
	}
	out[idx]=sm;
	return sm;
}
int main()
{
	freopen("runaway.out","w",stdout);
	freopen("runaway.in","r",stdin);
	long long i,j,k;
	scanf("%lld %lld",&n,&m);
	for(i=2;i<=n;i++)
	{
		scanf("%lld %lld",&p[i],&l[i]);
		adj[p[i]].emplace_back(i,l[i]);
	}
	dfs(1);
	dep(1);
	for(i=1;i<=n;i++)
	{
		printf("%lld\n",out[i]);
	}
}