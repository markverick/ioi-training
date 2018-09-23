#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int p[3005],mat[3005][3005],d[3005][3005],root;
vector<pair<int,int> > adj[3005];
inline int Find(int x)
{
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
}
inline int Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    p[x]=y;
}
vector<tuple<int,int,int> > e,v;
void dfs(int idx,int p,int dist)
{
	d[root][idx]=dist;
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p)continue;
		dfs(adj[idx][i].X,idx,dist+adj[idx][i].Y);
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,c,n,fk=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		for(j=1;j<=n;j++)
		{
			if(i==j)continue;
			scanf("%d",&mat[i][j]);
			e.emplace_back(mat[i][j],i,j);
		}
	}
	sort(e.begin(),e.end());
	for(i=0;i<e.size();i++)
	{
		tie(c,a,b)=e[i];
		if(Find(a)!=Find(b))
		{
			Union(a,b);
			adj[a].emplace_back(b,c);
			adj[b].emplace_back(a,c);
			e[i]=MT(0,0,0);
			v.emplace_back(a,b,c);
		}
	}
	for(root=1;root<=n;root++)
		dfs(root,0,0);
	for(i=0;i<e.size();i++)
	{
		tie(c,a,b)=e[i];
		if(c==mat[a][b]&&c!=d[a][b])
		{
			v.emplace_back(a,b,c);break;
		}
	}
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++)
	{
		tie(a,b,c)=v[i];
		printf("%d %d %d\n",a,b,c);
	}


	// return 0;
	// for(i=0;i<e.size();i++)
	// {
	// 	tie(c,a,b)=e[i];fk=0;
	// 	if(c==0)continue;
	// 	for(j=0;j<adj[a].size();j++)
	// 		if(mat[a][adj[a][j]]<c)fk=1;
	// 	for(j=0;j<adj[b].size();j++)
	// 		if(mat[b][adj[b][j]]<c)fk=1;
	// 	if(fk==0)
	// 	{
	// 		v.emplace_back(a,b,c);
	// 	}
	// }
}