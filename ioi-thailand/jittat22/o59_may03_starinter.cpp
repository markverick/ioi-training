#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
typedef class node
{
public:
	node *l=NULL,*r=NULL;
	int prior,val,size;
	node(int t)
	{
		prior=rand()*(1<<15)+rand();
		val=t;size=1;
	}
} node;
typedef node* pnode;
inline int sz(pnode t)
{
	return t?t->size:0;
}
inline void upz(pnode t)
{
	if(t)t->size=sz(t->l)+sz(t->r)+1;
}
inline void split(pnode t,pnode &l,pnode &r,int key)
{
	if(!t)l=r=NULL;
	else if(t->val<=key)split(t->r,t->r,r,key),l=t;
	else split(t->l,l,t->l,key),r=t;
	upz(t);
}
inline void merge(pnode &t,pnode l,pnode r)
{
	if(!l)t=r;
	else if(!r)t=l;
	else if(l->prior>=r->prior) merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upz(t);
}
inline void insert(pnode &t,int key)
{
	pnode l,r,it=new node(key);
	split(t,l,r,key);
	merge(t,l,it);
	merge(t,t,r);
}
inline int query(pnode &t,int key)
{
	pnode l,r;
	int out;
	split(t,l,r,key);
	out=sz(l);
	merge(t,l,r);
	return out;
}
int s,x;
int deg[200135];
vector<int> v[200135];
vector<pair<int,int> > adj[200135];
inline void dfs(int idx,int p)
{
	for(int i=0;i<adj[idx].size();i++)
	{
		if(adj[idx][i].X==p)continue;
		v[x].emplace_back(adj[idx][i].Y);
		dfs(adj[idx][i].X,idx);
	}
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b,c;
	long long sum=0,sm=0,m;
	pnode root=NULL;
	scanf("%d %d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d %d %d",&a,&b,&c);
		deg[a]++;deg[b]++;
		adj[a].emplace_back(b,c);
		adj[b].emplace_back(a,c);
	}
	for(i=1;i<=n;i++)
	{
		if(deg[i]>2)
		{
			s=adj[i].size();
			for(x=0;x<adj[i].size();x++)
			{
				v[x].emplace_back(adj[i][x].Y);
				dfs(adj[i][x].X,i);
				k=0;sm=0;
				for(j=0;j<v[x].size();j++)
				{
					// printf("%d ",v[x][j]);
					sm+=v[x][j];
					while(sm>m)
						sm-=v[x][k++];
					sum+=j-k+1;
				}
				// printf("\n=%d\n",sum);
			}
			break;
		}
	}
	if(s==0)
	{
		for(i=1;i<=n;i++)
		{
			if(deg[i]==1)
			{
				x=0;
				dfs(i,0);
				k=0;sm=0;
				for(j=0;j<v[x].size();j++)
				{
					// printf("%d ",v[x][j]);
					sm+=v[x][j];
					while(sm>m)
						sm-=v[x][k++];
					sum+=j-k+1;
				}
				printf("%lld",sum);
				return 0;
			}
		}
	}
	// printf("%d\n",sum);
	for(x=0;x<s;x++)
	{
		sm=0;
		for(j=0;j<v[x].size();j++)
		{
			sm+=v[x][j];
			sum+=query(root,m-sm);
		}
		sm=0;
		for(j=0;j<v[x].size();j++)
		{
			sm+=v[x][j];
			insert(root,sm);
		}
	}
	printf("%lld",sum);
}