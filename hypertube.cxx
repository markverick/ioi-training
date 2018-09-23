#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> gnai[101135],adj[1135];
priority_queue<pair<int,int> > pq;
int d[101135];
int main()
{
	int i,j,k,n,m,s,u,w,a;
	scanf("%d %d %d",&n,&s,&m);
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=s;j++)
		{
			scanf("%d",&a);
			adj[n+i].emplace_back(a);
			adj[a].emplace_back(n+i);
		}
	}
	for(i=1;i<=101111;i++)
		d[i]=MI;
	d[1]=0;
	pq.emplace(0,1);
	while(!pq.empty())
	{
		tie(w,u)=pq.top();
		w=-w;
		pq.pop();
		for(i=0;i<adj[u].size();i++)
		{
			if(w+1<d[adj[u][i]])
			{
				d[adj[u][i]]=w+1;
				pq.emplace(-w-1,adj[u][i]);
			}
		}
	}
	if(d[n]<MI)
		printf("%d\n",d[n]/2+1);
	else
		printf("-1\n");
}