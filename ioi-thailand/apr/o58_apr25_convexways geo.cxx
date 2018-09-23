#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int p[13][2135],d[13][2135],a[2135],b[2135];
double base;
double pi;
pair<int,int> pt[2135];
pair<int,int> operator -(pair<int,int> a,pair<int,int> b)
{
	return MP(a.X-b.X,a.Y-b.Y);
}
int dir2(pair<int,int> p,pair<int,int> q)
{
	return k=p.X*q.Y-p.Y*p.X>=0;// left is 1 right is 0
}
int dir(int a,int b,int c)
{
	if(a==0)return 0;
	return dir2(pt[b]-pt[a],pt[c]-pt[b]);
}
double ang(int a,int b)
{
	pair<int,int> v=pt[b]-pt[a];
	double tmp=atan2(v.Y,v.X);
	if(tmp<0)tmp+=pi;
}
void dfs(int a,int b,int dr)
{
	int i;
	for(i=0;i<adj[idx].size();i++)
	{
		c=adj[idx][i];
		if(dr==2)dfs(b,c,dir(a,b,c));
		else if(dr==dir(a,b,c))dfs(b,c,dir(a,b,c));
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	pi=acos(-1.0);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&pt[i],&pt[i]);
	}
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
		adj[a[i]].emplace_back(b[i]);
		adj[b[i]].emplace_back(a[i]);
	}
	for(i=1;i<=n;i++)
	{
		memset(ste,0,sizeof ste);
		for(j=0;j<adj[i].size();j++)
		{
			root=ang(i,adj[i][j])
			dfs(i,adj[i][j]);
		}
	}
}