#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int deg[10135],hsh[10135],ste[10135],d[20][20],dist[70135],ds[10135];
vector<int> adj[10135],v;
priority_queue<pair<int,int> > pq;
void dfs(int u,int idx,int sum,int p)
{
	// printf("%d %d %d\n",u,idx,sum);
	if(sum&&hsh[idx]>=0)
	{
		d[hsh[u]][hsh[idx]]=min(d[hsh[u]][hsh[idx]],sum);
		return;
	}
	if(idx!=u)
		ste[idx]=1;
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p||ste[adj[idx][i]])continue;
		dfs(u,adj[idx][i],sum+1,idx);
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	queue<pair<int,int> > q;
	int n,m,a,b,i,j,k,w,bit,u;
	memset(hsh,-1,sizeof hsh);
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
		for(j=0;j<=n;j++)
			ds[j]=MI;
		for(j=0;j<adj[v[i]].size();j++)
		{
			q.emplace(adj[v[i]][j],v[i]);	
			ds[adj[v[i]][j]]=1;
		}
		while(!q.empty())
		{
			tie(u,w)=q.front();
			q.pop();
			if(hsh[u]>=0)continue;
			for(j=0;j<adj[u].size();j++)
			{
				if(adj[u][j]==w)continue;
				if(ds[adj[u][j]]==MI)
					q.emplace(adj[u][i],u),ds[adj[u][j]]=ds[u]+1;
			}
		}
		for(j=0;j<v.size();j++)
		{
			d[i][j]=ds[v[j]];
		}
	}
	for(i=0;i<v.size();i++)
	{
		for(j=0;j<v.size();j++)
		{
			printf("%d <-> %d = %d\n",v[i],v[j],d[i][j]);
		}
	 }
	for(i=1;i<=66000;i++)
		dist[i]=MI;
	dist[0]=0;
	pq.emplace(0,0);
	while(!pq.empty())
	{
		tie(w,bit)=pq.top();
		pq.pop();
		w=-w;
		for(i=0;i<v.size();i++)
		{
			for(j=i;j<v.size();j++)
			{
				if(d[i][j]>=MI)continue;
				if(w+d[i][j]<dist[bit^(1<<i)^(1<<j)])
				{
					dist[bit^(1<<i)^(1<<j)]=w+d[i][j];
					pq.emplace(-w-d[i][j],bit^(1<<i)^(1<<j));
				}
			}
		}
	}
	printf("%d",m-dist[(1<<v.size())-1]);
}