#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int pa[222],hi[222],lca[222],L[222],R[222],x[333],y[333];
vector<int> adj[222];
int hsh[222],ha[222],mn=MI,n,m;
pair<int,int> ord[333];
void dfs(int idx,int p,int h)
{
	hi[idx]=h;
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==p)continue;
		pa[adj[idx][i]]=idx;
		dfs(adj[idx][i],idx,h+1);
	}
}
void dep(int idx,int c)
{
	int i,id,a,fk=0;
	if(idx==m+1)
	{
		if(c<mn)
		{
			mn=c;
			for(i=1;i<=n;i++)
				ha[i]=hsh[i];
		}
		return;
	}
	if(c>10)return;
	id=ord[idx].Y;
	a=x[id];
	while(a!=lca[id])
	{
		if(hsh[a])
			fk=1;
		a=pa[a];
	}
	a=y[id];
	while(a!=lca[id])
	{
		if(hsh[a])
			fk=1;
		a=pa[a];
	}
	if(fk==0)
	{
		if(c+1>10||c+1>mn)
			return;
		hsh[L[id]]++;
		dep(idx+1,c+1);
		hsh[L[id]]--;
		if(R[id])
		{
			hsh[R[id]]++;
			dep(idx+1,c+1);
			hsh[R[id]]--;
		}
	}
	else
	{
		if(c>mn)return;
		dep(idx+1,c);
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x[i],&y[i]);
	}
	dfs(1,0,1);
	for(i=1;i<=m;i++)
	{
		if(hi[x[i]]<hi[y[i]])swap(x[i],y[i]);
		a=x[i];b=y[i];
		while(hi[a]>hi[b])
		{
			L[i]=a;R[i]=0;
			a=pa[a];
		}
		while(a!=b)
		{
			L[i]=a;R[i]=b;
			a=pa[a],b=pa[b];
		}
		lca[i]=a;
		ord[i]=MP(-hi[lca[i]],i);
	}
	sort(&ord[1],&ord[m+1]);
	for(i=1;i<=m;i++)
	{
		a=ord[i].Y;
		// printf("{%d} %d << %d < [%d] > %d >> %d\n",ord[a].X,x[a],L[a],lca[a],R[a],y[a]);
	}
	dep(1,0);
	k=0;
	for(i=1;i<=n;i++)
	{
		if(ha[i])
			k++;
	}
	printf("%d\n",k);
	for(i=1;i<=n;i++)
	{
		if(ha[i])
			printf("%d %d\n",i,pa[i]);
	}
}