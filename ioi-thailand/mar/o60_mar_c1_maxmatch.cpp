#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[12],y[12],n,m,hsh[10135],w[12],jum[10135][2];
vector<pair<int,int> > adj[10135];
vector<int> ::iterator it;
int dp(int idx,int p,int used)
{
	int i,mc=0,sm=0;
	if(jum[idx][used]>=0)return jum[idx][used];
	if(hsh[idx])used=1;
	if(used==0)
	{
		for(i=0;i<adj[idx].size();i++)
		{
			if(adj[idx][i].X==p)continue;
			sm+=dp(adj[idx][i].X,idx,0);
		}
		mc=max(mc,sm);
		for(i=0;i<adj[idx].size();i++)
		{
			if(adj[idx][i].X==p)continue;
			if(hsh[adj[idx][i].X])continue;
			sm-=dp(adj[idx][i].X,idx,0);
			mc=max(mc,sm+dp(adj[idx][i].X,idx,1)+adj[idx][i].Y);
			sm+=dp(adj[idx][i].X,idx,0);
		}
	}
	else
	{
		sm=0;
		for(i=0;i<adj[idx].size();i++)
		{
			if(adj[idx][i].X==p)continue;
			sm+=dp(adj[idx][i].X,idx,0);
		}
		mc=max(mc,sm);
	}
	return jum[idx][used]=mc;
}
int gen(int idx,int sm=0)
{
	int mc=0;
	if(idx==m)
	{
		memset(jum,-1,sizeof jum);
		return dp(1,0,0)+sm;
	}
	hsh[x[idx]]++;
	hsh[y[idx]]++;
	if(hsh[x[idx]]<=1&&hsh[y[idx]]<=1)
		mc=max(mc,gen(idx+1,sm+w[idx]));
	hsh[x[idx]]--;
	hsh[y[idx]]--;
	mc=max(mc,gen(idx+1,sm));
	return mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,c;
	scanf("%d %d",&n,&m);
	for(i=1;i<n;i++)
		scanf("%d %d %d",&a,&b,&c),adj[a].emplace_back(b,c),adj[b].emplace_back(a,c);
	for(i=0;i<m;i++)
	{
		scanf("%d %d %d",&x[i],&y[i],&w[i]);
	}
	memset(jum,-1,sizeof jum);
	if(m==0)
		printf("%d\n",dp(1,0,0));
	else
		printf("%d\n",gen(0));
}