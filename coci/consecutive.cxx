#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int o[10135],p[10135],h[10135];
vector<int> adj[10135];
int up[10135],down[10135],jum[10135][105];
void dfs(int idx,int hi)
{
	h[idx]=hi;
	for(int i=0;i<adj[idx].size();i++)
		dfs(adj[idx][i],hi+1);
}
int dup(int idx)
{
	int sm=1,i;
	for(i=0;i<adj[idx].size();i++)
	{
		if(o[adj[idx][i]]==o[idx]+1)
			sm+=dup(adj[idx][i]);
		else
			dup(adj[idx][i]);
	}
	up[idx]=sm;
	return sm;
}
int ddown(int idx)
{
	int sm=1,i;
	for(i=0;i<adj[idx].size();i++)
	{
		if(o[adj[idx][i]]==o[idx]-1)
			sm+=ddown(adj[idx][i]);
		else
			ddown(adj[idx][i]);
	}
	down[idx]=sm;
	return sm;
}
int dp(int idx,int low)
{
	int i,sm=1,hi=low+h[idx],asc=0,dsc=0;
	for(i=0;i<adj[idx].size();i++)
	{
		if(o[adj[idx][i]]==low-1)
			sm+=dp(adj[idx][i],low-1),dsc+=down[adj[idx][i]];
		else if(o[adj[idx][i]]==hi+1)
			sm+=dp(adj[idx][i],low),asc+=up[adj[idx][i]];
	}
	sm+=dsc*asc;
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&o[i]);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].emplace_back(b);
		p[b]=a;
	}
	dfs(1,0);
	dup(1);
	ddown(1);
	for(i=1;i<=n;i++)
	{
		// up[i]++;down[i]++;
		// printf("%d: up = %d, down = %d\n",i,up[i],down[i]);
	}
	printf("%d\n",dp(1,o[1]));
}