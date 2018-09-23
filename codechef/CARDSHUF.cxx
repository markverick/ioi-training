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
	int val,size,prior,inv;
	node(const int v)
	{
		inv=0;prior=rand()*(1<<15)+rand();l=r=NULL;val=v;size=1;
	}
}node;
typedef node* pnode;
int sz(pnode t)
{
	return t?t->size:0;
}
void upz(pnode t)
{
	if(t)t->size=sz(t->l)+sz(t->r)+1;
}
void invert(pnode t)
{
	if(!t||t->inv==0)return;
	swap(t->l,t->r);
	t->inv=0;
	if(t->l)t->l->inv^=1;
	if(t->r)t->r->inv^=1;
	// upz(t);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
	if(!t) {l=r=NULL;return;}
	invert(t);
	int cpos=sz(t->l)+add;
	if(cpos<pos) split(t->r,t->r,r,pos,cpos+1),l=t;
	else split(t->l,l,t->l,pos,add),r=t;
	upz(t);
}
void merge(pnode &t,pnode l,pnode r)
{
	invert(l);invert(r);
	if(!l) t=r;
	else if(!r)t=l;
	else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upz(t);
}
void print(pnode t)
{
	if(!t)return;
	invert(t);
	print(t->l);
	printf("%d ",t->val);
	print(t->r);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	srand(135);
	int n,i,j,k,m,a,b,c;
	scanf("%d %d",&n,&m);
	pnode root=NULL,it,A,B,C,base;
	for(i=1;i<=n;i++)
	{
		it=new node(i);
		merge(root,root,it);
	}
	while(m--)
	{
		scanf("%d %d %d",&a,&b,&c);
		split(root,A,root,a);
		split(root,B,root,b);
		merge(root,A,root);
		split(root,C,root,c);
		if(B)B->inv^=1;
		merge(root,B,root);
		merge(root,C,root);
	}
	print(root);
	printf("\n");
}