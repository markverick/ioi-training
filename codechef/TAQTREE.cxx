#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int h[100135],a[100135],b[100135],c[100135],sp[20][100135],pos[100135],id=1,cnum=1,sze[100135],cnai[100135],chead[100135],cpos[100135],csize[100135];
vector<pair<int,int> > adj[100135];
int ft[100135],n;
void add(int x,int val)
{
	while(x<=100010)
	{
		ft[x]+=val;
		x+=x&-x;
	}
}
int sum(int x)
{
	int sm=0;
	while(x>0)
	{
		sm+=ft[x];
		x-=x&-x;
	}
	return sm;
}
int upd(int x,int val)
{
	int y=sum(x)-sum(x-1);
	add(x,-y+val);
}
void hld(int idx,int p,int cost)
{
	sze[idx]=1;id++;
	if(chead[cnum]==0)
		chead[cnum]=idx;
	cnai[idx]=cnum;
	csize[cnum]++;
	cpos[idx]=csize[cnum];
	pos[idx]=id;
	add(id,cost);
	int mc=-1,ind=-1,i;
	// printf("%d %d %d\n",idx,p,cost);
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p)continue;
		if(mc<sze[adj[idx][i].X])
			mc=sze[adj[idx][i].X],ind=i;
	}
	if(ind>=0)
		hld(adj[idx][ind].X,idx,adj[idx][ind].Y);
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p||i==ind)continue;
		cnum++;
		hld(adj[idx][i].X,idx,adj[idx][i].Y);
	}
}
void dfs(int idx,int p,int lv)
{
	h[idx]=lv;
	sze[idx]=1;
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p)continue;
		dfs(adj[idx][i].X,idx,lv+1);
		sp[0][adj[idx][i].X]=idx;
		sze[idx]+=sze[adj[idx][i].X];
	}
}
int lca(int x,int y)
{
	if(h[x]<h[y])
		swap(x,y);
	int i;
	for(i=18;i>=0;i--)
	{
		if(h[sp[i][x]]>=h[y])
			x=sp[i][x];
	}
	if(x==y)
		return x;
	for(i=18;i>=0;i--)
	{
		if(sp[i][x]!=sp[i][y])
			x=sp[i][x],y=sp[i][y];
 
	}
	return sp[0][x];
}
int dist(int x,int y)
{
	int sm=0,p;
	while(cnai[x]!=cnai[y])
	{
		p=chead[cnai[x]];
		sm+=sum(pos[x])-sum(pos[p]-1);
		x=sp[0][p];
	}
	sm+=sum(pos[x])-sum(pos[y]);
	// printf("+%d-%d ->%d\n",sum(pos[x]),sum(pos[y]),sm);
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,Q,ch,u,v,lc;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&c[i]);
		adj[a[i]].emplace_back(b[i],c[i]);
		adj[b[i]].emplace_back(a[i],c[i]);
	}
	dfs(1,0,1);
	for(i=1;i<=18;i++)
		for(j=1;j<=n;j++)
			sp[i][j]=sp[i-1][sp[i-1][j]];
	hld(1,0,0);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d %d %d",&ch,&u,&v);
		if(ch==1)
		{
			if(h[a[u]]<h[b[u]])
				swap(a[u],b[u]);
			upd(pos[a[u]],v);
		}
		else
		{
			lc=lca(u,v);
			printf("%d\n",dist(u,lc)+dist(v,lc));
		}
	}
	
} 