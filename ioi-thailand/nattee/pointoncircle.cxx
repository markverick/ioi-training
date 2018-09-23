#include<bits/stdc++.h>
#define MI 1000000005
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m,mat[1135][1135],ste[1135],L[1135],R[1135];
vector<pair<int,int> > adj[1135];
vector<pair<int,int> > v;
void dfs(int idx,int p)
{
	ste[idx]=1;
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p)
			continue;
		if(ste[adj[idx][i].X])
		{
			L[idx]=adj[idx][i].X;
			R[adj[idx][i].X]=idx;
			continue;
		}
		R[idx]=adj[idx][i].X;
		L[adj[idx][i].X]=idx;
		dfs(adj[idx][i].X,idx);
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		mn.clear();
		for(j=1;j<=m;j++)
		{
			scanf("%d",&mat[i][j]);
			if(mat[i][j])
				mn.insert(mat[i][j],j);
		}
		// printf("(%d,%d) - (%d,%d)\n",mn.l.X,mn.l.Y,mn.h.X,mn.h.Y);
		adj[i].emplace_back(mn.l.Y,mn.l.X);
		adj[i].emplace_back(mn.h.Y,mn.h.X);
	}
	dfs(1,0);
	for(i=1;i<=m;i++)
	{
		printf("%d <- %d -> %d\n",L[i],i,R[i]);
	}
	int sm=0;
	printf("%d\n",sm);
	// for(j=0;j<=m;j++)
	// {
	// 	for(i=1;i<=m;i++)
	// 	{
	// 		if(L)
	// 	}
	// }
}