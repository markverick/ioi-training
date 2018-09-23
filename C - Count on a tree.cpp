#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int n,w[200005],mp[200005],p[20][200005],h[200005],x,L[200005],R[200005],ar[200005];
pair<int,int> s[200005];
vector<int> adj[200005];
typedef struct node
{
	node *l=NULL,*r=NULL;
	int s=1;
}node;
typedef node* pnode;
pnode root[200005];
void build(pnode &t,int fs,int ls)
{
	t=new node;
	t->s=0;
	if(fs==ls) return;
	int md=(fs+ls)/2;
	build(t->l,fs,md);
	build(t->r,md+1,ls);
	t->s=t->l->s+t->r->s;
}
pnode update(pnode t,int fs,int ls)
{
	if(fs==ls)
		return new node;
	int md=(fs+ls)/2;
	pnode it=new node;
	*it=*t;
	if(x<=md) it->l=update(t->l,fs,md);
	else it->r=update(t->r,md+1,ls);
	it->s=it->l->s+it->r->s;
	return it;
}
int kth(pnode L1,pnode R1,pnode L2,pnode R2,int fs,int ls,int key)
{
	if(fs==ls)
		return s[fs].X;
	int md=(fs+ls)/2;
	int l=R1->l->s-L1->l->s + R2->l->s-L2->l->s;
	if(key<=l)
		return kth(L1->l,R1->l,L2->l,R2->l,fs,md,key);
	else
		return kth(L1->r,R1->r,L2->r,R2->r,md+1,ls,key-l);
}
int C=0;
void dfs(int idx,int pa,int hi)
{
	h[idx]=hi;
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==pa)continue;
		p[0][adj[idx][i]]=idx;
		dfs(adj[idx][i],idx,hi+1);
	}
}
inline int lca(int a,int b)
{
	int i;
	if(h[a]<h[b])swap(a,b);
	for(i=19;i>=0;i--)
		if(h[p[i][a]]>=h[b])
			a=p[i][a];
	if(a==b)
		return a;	
	for(i=19;i>=0;i--)
		if(p[i][a]!=p[i][b])
			a=p[i][a],b=p[i][b];
	return p[0][a];
}
void dep(int idx,int pa)
{
	x=mp[idx];
	root[idx]=update(root[p[0][idx]],1,n);
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i]==pa)continue;
		dep(adj[idx][i],idx);
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,m,a,b,l,ca,cb;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]),s[i]=MP(w[i],i);
	sort(&s[1],&s[n+1]);
	for(i=1;i<=n;i++)
		mp[s[i].Y]=i;
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&a,&b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	build(root[0],1,n);
	dfs(1,0,1);
	for(i=1;i<=19;i++)
		for(j=1;j<=n;j++)
			p[i][j]=p[i-1][p[i-1][j]];
	dep(1,0);
	while(m--)
	{
		scanf("%d %d %d",&a,&b,&k);
		l=lca(a,b);
		printf("%d\n",kth(root[p[0][l]],root[a],root[l],root[b],1,n,k));
	}
}