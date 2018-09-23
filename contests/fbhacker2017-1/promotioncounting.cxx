#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[200135],L[200135],R[200135],T=0,b[200135],p[200135],x,y;
vector<int> adj[200135];
int dfs(int idx)
{
	L[idx]=++T;
	b[T]=idx;
	int i;
	for(i=0;i<adj[idx].size();i++)
		dfs(adj[idx][i]);
	R[idx]=++T;
	b[T]=idx;
}
typedef class node
{
public:
	int val,size,prior;
	node *l,*r;
	node(int v)
	{
		val=v;size=1;prior=rand()*(1<<15)+rand();l=r=NULL;
	}
}node;
typedef node* pnode;
pnode seg[800135];
int sz(pnode t)
{
	return t?t->size:0;
}
void upz(pnode t)
{
	if(t) t->size=sz(t->l)+sz(t->r)+1;
}
void split(pnode t,pnode &l,pnode &r,int key)
{
	if(!t)l=r=NULL;
	else if(t->val<=key) split(t->r,t->r,r,key),l=t;
	else split(t->l,l,t->l,key),r=t;
	upz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
	if(!l) t=r;
	else if(!r)t=l;
	else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
	else  merge(r->l,l,r->l),t=r;
	upz(t);
}
void copy(pnode t,pnode &it)
{
	if(!t)
	{
		it=NULL;
		return;
	}
	pnode l=NULL,r=NULL;
	copy(t->l,l);
	copy(t->r,r);
	it=new node(t->val);
	it->l=l;it->r=r;it->prior=t->prior;
	upz(it);
}
int Find(pnode &t,int key)
{
	pnode l,r;
	split(t,l,r,key);
	int ret=sz(l);
	merge(t,l,r);
	return ret;
}
void build(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
	{
		seg[id]=new node(a[b[fs]]);
		return;
	}
	build(id*2,fs,md);
	build(id*2+1,md+1,ls);
	pnode t,l,r;
	copy(seg[id*2],l);
	copy(seg[id*2+1],r);
	merge(t,l,r);
	seg[id]=t;
}
int query(int id,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<x||fs>y)
		return 0;
	if(fs>=x&&ls<=y)
	{
		return sz(seg[id])-Find(seg[id],a[b[x-1]]);
	}
	return query(id*2,fs,md)+query(id*2+1,md+1,ls);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(i=2;i<=n;i++)
		scanf("%d",&p[i]),adj[p[i]].emplace_back(i);
	dfs(1);
	// for(i=1;i<=n*2;i++)
	// 	printf("%d ",b[i]);
	// printf("\n");
	build(1,1,n*2);
	for(i=1;i<=n;i++)
	{
		x=L[i]+1,y=R[i]-1;
		// printf("%d %d\n",x,y);
		if(x>y)
			printf("0\n");
		else
			printf("%d\n",query(1,1,n*2)/2);
	}
}