#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ste[100135],deg[100135],hsh[100135],cyc;
set<int> st[100135];
vector<int> v,adj[100135],u;
void dfs(int idx,int p)
{
	ste[idx]=1;
	v.emplace_back(idx);
	if(deg[idx]==3)
		cyc=idx;
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p)continue;
		if(ste[adj[idx][i]])continue;
		dfs(adj[idx][i],idx);
	}
}
int dep(int idx,int p)
{
	ste[idx]=2;
	u.emplace_back(idx);
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p)continue;
		if(ste[adj[idx][i]]==2)return 1;
		if(dep(adj[idx][i],idx))return 1;
	}
	return 0;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,sm=0,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		deg[a]++;deg[b]++;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(i=1;i<=n;i++)
	{
		if(ste[i])continue;
		cyc=0;v.clear();u.clear();
		dfs(i,0);
		if(!cyc)
		{
			hsh[v.size()]++;
		}
		else
		{
			dep(cyc,0);
			st[v.size()].insert(u.size());
		}
	}
	for(i=1;i<=n;i++)
	{
		sm+=hsh[i]>0;
		sm+=st[i].size();
	}
	printf("%d",sm);
}