#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int p[100135],h[100135],c[100135],seg[400135],hev[100135];
int L[100135],R[100135],head[100135],C=0,ar[100135],pos[100135],G=0,val,x,y;
vector<int> adj[100135];
void dfs(int idx,int hi)
{
	h[idx]=hi;
	c[idx]=1;
	int mc=0,x=0,i;
	for(i=0;i<adj[idx].size();i++)
	{
		dfs(adj[idx][i],hi+1);
		if(mc<c[adj[idx][i]])
			mc=c[adj[idx][i]],x=adj[idx][i];
		c[idx]+=c[adj[idx][i]];
	}
	hev[idx]=x;
}
void hld(int idx)
{
	int i;
	pos[idx]=++C;
	ar[C]=idx;
	if(hev[idx])
	{
		head[hev[idx]]=head[idx];
		hld(hev[idx]);
	}
	for(i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==hev[idx])continue;
		G++;
		head[adj[idx][i]]=adj[idx][i];
		hld(adj[idx][i]);
	}
}
void update(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		if(val) seg[id]=fs;
		else seg[id]=0;
		return;
	}
	if(x<=md)
		update(id*2,fs,md);
	else
		update(id*2+1,md+1,ls);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
int sum(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return 0;
	if(fs>=x&&ls<=y)
		return seg[id];
	return max(sum(id*2,fs,md),sum(id*2+1,md+1,ls));
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,id,fk,ch;
	scanf("%d %d",&n,&m);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&p[i]);
		adj[p[i]].emplace_back(i);
	}
	dfs(1,1);
	// for(i=1;i<=n;i++)
	// 	printf("%d\n",hev[i]);
	head[1]=1;
	hld(1);
	// for(i=1;i<=n;i++)
	// 	printf("%d %d\n",pos[i],head[i]);
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&ch,&x);
		if(ch==1)
		{
			x=pos[x];
			val=1;
			update(1,1,n);
		}
		else if(ch==2)
		{
			x=pos[x];
			val=0;
			update(1,1,n);
		}
		else
		{
			id=x;
			fk=0;
			while(id)
			{
				y=pos[id];x=pos[head[id]];
				if(fk=sum(1,1,n))
					break;
				id=p[head[id]];
			}
			fk=max(fk,1);
			printf("%d\n",ar[fk]);

		}
	}
}