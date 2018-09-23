#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<pair<long long,long long> > adj[500135];
long long target[500135],hsh[500135],far[500135],down[500135],L[500135],to[500135],all=0,n,m,root,fromst[500135];
vector<long long> up;
pair<long long,long long> fromlf[500135];
long long dfs(long long idx,long long p,long long mrk)
{
	long long i,sm=0,cot=0,j;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p)continue;
		fromst[adj[idx][i].X]=fromst[idx]+adj[idx][i].Y;
		j=dfs(adj[idx][i].X,idx,target[idx]?1:mrk);
		if(j)cot++;
		sm+=j;
	}
	if(cot>1||target[idx]==1||(sm&&sm<m))
	{
		hsh[idx]=1;
		root=idx;
	}
	else if(sm) up.emplace_back(idx);
	else if(mrk) down[idx]=1;
	if(target[idx]==1)sm++;
	return sm;
}
void dfs2(long long idx,long long p,long long len,long long towhat)
{
	long long i;
	L[idx]=len;
	to[idx]=towhat;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p)continue;
		if(hsh[adj[idx][i].X])
		{
			dfs2(adj[idx][i].X,idx,0,adj[idx][i].X);
			if(hsh[idx])
				all+=adj[idx][i].Y;
		}
		else
			dfs2(adj[idx][i].X,idx,len+adj[idx][i].Y,towhat);
	}
}
void dfs3(long long idx,long long p,long long len)
{
	long long i;
	L[idx]=len;
	to[idx]=root;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p||hsh[adj[idx][i].X])continue;
		dfs3(adj[idx][i].X,idx,len+adj[idx][i].Y);
	}
}
void append(pair<long long,long long> &p,long long x)
{
	if(x>p.X)
	{
		swap(p.X,p.Y);
		p.X=x;
	}
	else if(x>p.Y) p.Y=x;
}
pair<long long,long long> dfs4(long long idx,long long p) //Find length from down
{
	long long i;
	pair<long long,long long> mc={0,0},q;
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p||hsh[adj[idx][i].X]==0)continue;
		q=dfs4(adj[idx][i].X,idx);
		append(mc,q.X+adj[idx][i].Y);
	}
	fromlf[idx]=mc;
	return mc;
}
void dfs5(long long idx,long long p,long long len)
{
	long long i;
	far[idx]=max(fromlf[idx].X,len);
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p||hsh[adj[idx][i].X]==0)continue;
		if(fromlf[adj[idx][i].X].X+adj[idx][i].Y==fromlf[idx].X)
			dfs5(adj[idx][i].X,idx,adj[idx][i].Y+max(len,fromlf[idx].Y));
		else
			dfs5(adj[idx][i].X,idx,adj[idx][i].Y+max(len,fromlf[idx].X));
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,a,b,c;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}
	for(i=1;i<=m;i++)
		scanf("%lld",&a),target[a]=1;
	dfs(1,0,0);
	if(up.empty())up.emplace_back(0);
	dfs2(root,up[0],0,root);
	dfs3(root,0,0);
	dfs4(root,0);
	dfs5(root,0,0);
	// for(i=1;i<=n;i++)
	// {
	// 	if(hsh[i])
	// 	{
	// 		prlong longf("[%lld] From Leaf = %lld > %lld || Farthest = %lld\n",i,fromlf[i].X,fromlf[i].Y,far[i]);
	// 	}
	// }
	// prlong longf("\n");
	// for(i=1;i<=n;i++)
	// 	prlong longf("[%lld] Length = %lld to %lld\n",i,L[i],to[i]);
	for(i=1;i<=n;i++)
	{
		printf("%lld\n",all*2+L[i]-far[to[i]]);
	}
}