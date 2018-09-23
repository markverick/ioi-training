#include<bits/stdc++.h>
#define MI 1000000005
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m,mat[1135][1135],p[1135],ste[1135],deg[1135],out[1135];
vector<tuple<int,int,int> > e;
vector<pair<int,int> > v,adj[1135];
int Find(int x)
{
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
}
int Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    p[x]=y;
}
void dfs(int idx,int p)
{
	ste[idx]=1;
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p||ste[adj[idx][i].X]==1)
			continue;
		v.emplace_back(idx,adj[idx][i].Y);
		dfs(adj[idx][i].X,idx);
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,a,b,w;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		p[i]=i;
		for(j=1;j<=m;j++)
		{
			scanf("%d",&mat[i][j]);
			if(j>i)
				e.emplace_back(mat[i][j],i,j);
		}
	}
	sort(e.begin(),e.end());
	for(i=0;i<e.size();i++)
	{
		tie(w,a,b)=e[i];
		if(Find(a)!=Find(b))
		{
			Union(a,b);
			adj[a].emplace_back(b,mat[a][b]);
			adj[b].emplace_back(a,mat[a][b]);
			deg[a]++;deg[b]++;
		}
	}
	int s=0,t=0,sm=0;
	for(i=1;i<=m;i++)
	{
		if(s==0&&deg[i]==1)
			s=i;
		else if(s&&deg[i]==1)
			t=i;
	}
	dfs(s,0);
	// printf("%d %d\n",s,t);
	for(i=0;i<v.size();i++)
	{
		// printf("%d\n",v[i].X);
		out[v[i].X]=sm;
		sm+=v[i].Y;
	}
	out[t]=sm;
	for(i=1;i<=m;i++)
		printf("%d\n",out[i]);
}