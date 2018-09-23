#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int deg[10135],hsh[10135],jum[70000],ste[10135],ds[10135],d[20][10135];
vector<int> adj[10135],v;
int dp(int bit)
{
	if(jum[bit]>=0)return jum[bit];
	int i,mn=MI,j;
	if(__builtin_popcount(bit)==v.size())
		return 0;
	for(i=0;i<v.size();i++)
	{
		for(j=i+1;j<v.size();j++)
		{
			if((bit&(1<<i))||(bit&(1<<j)))continue;
			mn=min(mn,dp(bit|(1<<i)|(1<<j))+d[i][j]);
		}
	}
	return jum[bit]=mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,a,b,i,j,k,u;
	queue<int> q;
	memset(hsh,-1,sizeof hsh);
	memset(jum,-1,sizeof jum);
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d %d",&a,&b),deg[a]++,deg[b]++,adj[a].emplace_back(b),adj[b].emplace_back(a);
	for(i=1;i<=n;i++)
	{
		if(deg[i]%2)
			v.emplace_back(i),hsh[i]=v.size()-1;
	}
	for(i=0;i<v.size();i++)
		for(j=0;j<v.size();j++)
			d[i][j]=MI;
	for(i=0;i<v.size();i++)
	{
		for(j=1;j<=n;j++)
			ds[j]=MI;
		q.emplace(v[i]);
		ds[v[i]]=0;
		while(!q.empty())
		{
			u=q.front();
			q.pop();
			for(j=0;j<adj[u].size();j++)
			{
				if(ds[adj[u][j]]==MI)
					q.emplace(adj[u][j]),ds[adj[u][j]]=ds[u]+1;
			}
		}
		for(j=0;j<v.size();j++)
			d[i][j]=ds[v[j]];
	}
	// for(i=0;i<v.size();i++)
	// {
	// 	for(j=0;j<v.size();j++)
	// 	{
	// 		printf("%d <-> %d = %d\n",v[i],v[j],d[i][j]);
	// 	}
	//  }
	printf("%d",m-dp(0));
}