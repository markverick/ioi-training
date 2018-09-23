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
	node *l,*r;
	int val,prior,size,cost;
	node(const int v,int c)
	{
		val=v;cost=c;prior=rand()*(1<<15)+rand();size=1;l=NULL;r=NULL;
	}
}node;
typedef node *pnode;
int sze(pnode t)
{
	return t?t->size:0;
}
void upz(pnode t)
{
	if(t)t->size=sze(t->l)+sze(t->r)+1;
}
void split(pnode t,pnode &l,pnode &r,int key)
{
	if(!t)l=NULL,r=NULL;
	else if(t->val<=key) split(t->r,t->r,r,key),l=t;
	else split(t->l,l,t->l,key),r=t;
	upz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
	if(!l)t=r;
	else if(!r)t=l;
	else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upz(t);
}
void insert(pnode &t,int key,int c) ///multiset
{
	pnode l,r,md,it=new node(key,c);
	split(t,l,r,key);
	split(l,l,md,key-1);
	merge(t,l,it);
	merge(t,t,r);
}
void erase(pnode &t,int key)
{
	pnode l,r,md;
	split(t,l,r,key);
	split(l,l,md,key-1);
	if(md) delete md;
	merge(t,l,r);
}
int main()
{
	srand(1998);
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,T,a,b;
	char ch[3];
	scanf("%d %d",&n,&m);
	T=n+m;
	pnode root=NULL;
	pnode p;
	while(T--)
	{
		scanf("%s",ch);
		if(ch[0]=='A')
		{
			scanf("%d %d",&a,&b);
			insert(root,a,b);
		}
		else if(ch[0]=='B')
		{
			p=root;
			if(!p)
			{
				printf("0\n");continue;
			}
			while(p->l)
				p=p->l;
			printf("%d\n",p->cost);
			erase(root,p->val);
		}
		else
		{
			p=root;
			if(!p)
			{
				printf("0\n");continue;
			}
			while(p->r)
				p=p->r;
			printf("%d\n",p->cost);
			erase(root,p->val);
		}
	}
}