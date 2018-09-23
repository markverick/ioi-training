#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int w[100135],p[100135],mc[100135];
inline int Find(int x)
{
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
}
inline int Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    p[x]=y;
}
typedef class node
{
public:
	node *l,*r;
	int val,size,prior;
	node(const int v)
	{
		prior=rand()*(1<<15)+rand();l=r=NULL;val=v;size=1;
	}
}node;
typedef node* pnode;
inline int sz(pnode t)
{
	return t?t->size:0;
}
inline void upz(pnode t)
{
	if(t)t->size=sz(t->l)+sz(t->r)+1;
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
	if(!t) {l=r=NULL;return;}
	int cpos=sz(t->l)+add;
	if(cpos<pos) split(t->r,t->r,r,pos,cpos+1),l=t;
	else split(t->l,l,t->l,pos,add),r=t;
	upz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
	if(!l) t=r;
	else if(!r)t=l;
	else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upz(t);
}
int find(pnode t,int key)
{
	if(key==sz(t->l)+1)
		return t->val;
	else if(key<=sz(t->l))
		return find(t->l,key);
	return find(t->r,key-sz(t->l)-1);
}
inline void erase(pnode &t,int key)
{
	pnode l,r,md;
	split(t,l,r,key);
	split(l,l,md,key-1);
	if(md) delete md;
	merge(t,l,r);
}
// void print(pnode t)
// {
// 	if(!t)return;
// 	print(t->l);
// 	printf("%d ",t->val);
// 	print(t->r);
// }
vector<int> v,u,uu;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	srand(135);
	int n,m,i,j,k,a,b,S,K;
	pnode root=NULL,aug=NULL;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		merge(root,root,new node(i));
		scanf("%d",&w[i]);
	}
	// print(root);
	for(i=1;i<=m;i++)
	{
		aug=NULL;
		// printf("\t!! %d - %d!!\n",sz(root),sz(aug));
		S=sz(root);
		scanf("%d %d",&a,&b);
		j=0;
		K=1;
		while(K+a*b<=S)
			K+=a*b;
		for(j=1;j<=S;j+=a*b)
		{
			for(k=j+a;k<j+a*b;k+=a)
			{
				// printf("( %d ",find(root,k-a));
				// printf("%d ",k);
				if(k>S)break;
				Union(find(root,k-a),find(root,k));
				// printf(")\n");
			}
			merge(aug,aug,new node(Find(find(root,j))));
				// printf(">%d ",j);
				// printf("<\n");
		}
		while(K+a<=S)
			K+=a;
		for(j=K;j>=1;j-=a)
			erase(root,j);
		merge(root,root,aug);
		// print(root);
		// printf("\n");
		// printf("!");
	}
	for(i=1;i<=n;i++)
	{
		mc[Find(i)]=max(mc[Find(i)],w[i]);
	}
	for(i=1;i<=n;i++)
	{
		mc[i]=mc[Find(i)];
		if(mc[i]<=w[i])
			printf("%d\n",w[i]);
		else
			printf("%d\n",mc[i]+1);
	}

}