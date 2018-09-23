#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int o[10135],p[10135],rist[10135][105];
vector<int> adj[10135];
void dfs(int idx)
{
	int i,j,k;
	for(i=0;i<adj[idx].size();i++)
	{
		dfs(adj[idx][i]);
		for(j=`)
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].emplace_back(b);
		p[b]=a;
	}
	dfs(1);
}