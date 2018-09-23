#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<pair<int,pair<int,int> > > adj[50135];
priority_queue<pair<int,int> > pq;
int d[50135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,T,i,j,k,fs,md,ls,mn,a,b,c,w,u;
	scanf("%d %d %d",&n,&m,&T);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		adj[a].emplace_back(b,MP(c,i));
		adj[b].emplace_back(a,MP(c,i));
	}
	fs=0;ls=m+1;mn=ls;
	while(fs<=ls)
	{
		md=(fs+ls)/2;
		for(i=0;i<=n;i++)
			d[i]=MI;
		d[1]=0;
		pq.emplace(0,1);
		while(!pq.empty())
		{
			tie(w,u)=pq.top();
			pq.pop();
			w=-w;
			for(i=0;i<adj[u].size();i++)
			{
				if(adj[u][i].Y.Y>md)continue;
				if(w+adj[u][i].Y.X<d[adj[u][i].X])
					d[adj[u][i].X]=w+adj[u][i].Y.X,pq.emplace(-d[adj[u][i].X],adj[u][i].X);
			}
		}
		if(d[n]<=T)
		{
			mn=min(mn,md);
			ls=md-1;
		}
		else
			fs=md+1;
	}
	if(mn>m)
		printf("-1");
	else
		printf("%d",mn);
}