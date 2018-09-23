#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,int> adj[2][100135];
pair<int,int> edge[100135];
int d[3][100135],n;
set<int> st;
void operator +=(pair<int,int> &p,int a)
{
	if(p.X==0)
		p.X=a;
	else if(p.Y==0)
		p.Y=a;
}
void operator -=(pair<int,int> &p,int a)
{
	if(p.X==a)
		p.X=0;
	else if(p.Y==a)
		p.Y=0;
	if(p.X==0)swap(p.X,p.Y);
}
int add(int a,int b)
{
	adj[0][a]+=b;
	adj[1][b]+=a;
}
int del(int e)
{
	adj[0][edge[e].X]-=edge[e].Y;
	adj[1][edge[e].Y]-=edge[e].X;
}
void dfs1(int idx,int T)
{
	st.insert(idx);
	if(T==0)return;
	if(adj[1][idx].X)
		dfs1(adj[1][idx].X,T-1);
	if(adj[1][idx].Y)
		dfs1(adj[1][idx].Y,T-1);
}
int dfs2(int idx,int T)
{
	if(st.find(idx)!=st.end())
		return 1;
	if(T==0)return 0;
	if(adj[0][idx].X)
		if(dfs2(adj[0][idx].X,T-1))return 1;
	if(adj[0][idx].Y)
		if(dfs2(adj[0][idx].Y,T-1))return 1;
	return 0;
}
void debug()
{
	int i;
	printf("ST: ");
	for(i=1;i<=n;i++)
	{
		if(d[0][i]<MI)
			printf("%d ",i);
	}
	printf("\n");
	printf("ED: ");
	for(i=1;i<=n;i++)
	{
		if(d[1][i]<MI)
			printf("%d ",i);
	}
	printf("\n");
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,a,b,Q,T,u,w,m,ch,fk,E;
	queue<int> q;
	scanf("%d %d %d %d",&n,&m,&T,&Q);
	E=m;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		edge[i]=MP(a,b);
		add(a,b);
	}
	// printf("%d %d\n",adj[0][1].X,adj[0][1].Y);
	while(Q--)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d %d",&a,&b);
			st.clear();
			dfs1(b,T/2);
			// debug();
			// debug();
			if(dfs2(a,T-T/2))
				printf("1\n");
			else
				printf("0\n");
			
		}
		else if(ch==3)
		{
			scanf("%d %d",&a,&b);
			edge[++E]=MP(a,b);
			add(a,b);
		}
		else
		{
			scanf("%d",&a);
			del(a);
		}
	}
}