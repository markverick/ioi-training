#include<bits/stdc++.h>

#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
typedef struct node
{
	node *l,*r;
	int val,size,prior,mx;
	node(int v)
	{
		val=mx=v;size=1;prior=rand()*(1<<15)+rand();l=r=NULL;
	}
}node;
typedef node* pnode;
inline int sz(pnode t)
{
	return t?t->size:0;
}
inline int hist(pnode t)
{
	return t?t->mx:-MI;
}
inline void upd(pnode &t)
{
	if(!t)return;
	t->size=sz(t->l)+sz(t->r)+1;
	t->mx=max(hist(t->l),hist(t->r));
	t->mx=max(t->mx,t->val);
}
inline void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
	if(!t)
	{
		l=r=NULL;
		return;
	}
	int cpos=sz(t->l)+add;
	if(cpos<pos) split(t->r,t->r,r,pos,cpos+1),l=t;
	else split(t->l,l,t->l,pos,add),r=t;
	upd(t);
}
inline void merge(pnode &t,pnode l,pnode r)
{
	if(!l)t=r;
	else if(!r)t=l;
	else if(l->prior>r->prior) merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd(t);
}
inline void insert(pnode &t,pnode it,int pos,int add=0)
{
	if(!t)
	{
		t=it;
		return;
	}
	int cpos=sz(t->l)+add;
	if(t->prior<it->prior)
	{
		split(t,it->l,it->r,pos,add);
		t=it;
	}
	else if(cpos<pos) insert(t->r,it,pos,cpos+1);
	else insert(t->l,it,pos,add);
	upd(t);
}
void print(pnode t)
{
	if(!t)return;
	print(t->l);
	printf("%d ",t->val);
	print(t->r);
}
inline void Max(int &out,pnode &t,int fs,int ls)
{
	pnode l,md,r;
	split(t,l,r,ls);
	split(l,l,md,fs-1);
	// print(l);printf("\n");
	// print(md);printf("\n");
	// print(r);printf("\n");
	out=md->mx;
	merge(t,l,md);
	merge(t,t,r);
}
int main()
{
	srand(135);
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int a,b,c,Q;
	scanf("%d",&Q);
	pnode root=NULL,x;
	char ch[3];
	while(Q--)
	{
		scanf("%s",ch);
		scanf("%d %d",&a,&b);
		if(ch[0]=='A')
		{
			x=new node(a);
			insert(root,x,b-1);
		}
		else
		{
			Max(c,root,a,b);
			printf("%d\n",c);
		}
		// print(root);
		// printf("\n");
	}
}