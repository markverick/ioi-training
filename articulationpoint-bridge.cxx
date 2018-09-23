//https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[100135];
int isbridge[100135],isart[100135],t=1,disc[100135],low[100135],ste[100135],p[100135];
void dfs(int idx)
{
	int i,j=0;
	ste[idx]=1;disc[idx]=low[idx]=t;t++;
	// printf(":: %d ::\n",idx);
	for(i=0;i<adj[idx].size();i++)
	{
		if(p[idx]==adj[idx][i])continue;
		if(ste[adj[idx][i]]==0)
		{
			j++;
			p[adj[idx][i]]=idx;
			dfs(adj[idx][i]);
			low[idx]=min(low[idx],low[adj[idx][i]]);
			if(low[adj[idx][i]]>=disc[idx]) //if loop is at idx and below == have at least art
				isart[idx]=1;
			if(low[adj[idx][i]]>disc[idx]) //if backedge at parent node == bridge
				isbridge[adj[idx][i]]=1;
		}
		else if(ste[adj[idx][i]]==1)
			low[idx]=min(low[idx],disc[adj[idx][i]]);
	}
	if(p[idx]==-1)
		isart[idx]=j>=2?1:0;
	ste[idx]=2;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,a,b;
	memset(p,-1,sizeof p);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(i=0;i<n;i++)
	{
		if(ste[i]>0)continue;
		dfs(i);
	}
	// for(i=0;i<n;i++)
	// {
	// 	printf("%d %d\n",disc[i],low[i]);
	// }
	int A=0,B=0;
	vector<pair<int,int> > v;
	for(i=0;i<n;i++)
		A+=isart[i];
	for(i=0;i<n;i++)
	{
		if(p[i]==-1)continue;
		if(isbridge[i])
		{
			B++;
			if(p[i]<=i)
				v.emplace_back(p[i],i);
			else
				v.emplace_back(i,p[i]);
		}
	}
	printf("%d\n",A);
	for(i=0;i<n;i++)
		if(isart[i])
			printf("%d ",i);
	printf("\n%d\n",B);
	sort(v.begin(),v.end());
	for(i=0;i<v.size();i++)
		printf("%d %d\n",v[i].X,v[i].Y);
}