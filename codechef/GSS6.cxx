#include<bits/stdc++.h>
#define MI 1000000005
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
	int val,prior,size,L,R,M,sum;
	node(int v)
	{
		size=1;prior=rand()*(1<<15)+rand();sum=val=M=v;R=L=max(0,v);r=l=NULL;
	}
}node;
typedef node* pnode;
int max(int a,int b,int c)
{
	return max(max(a,b),c);
}
int sz(pnode t)
{
	return t?t->size:0;
}
int sm(pnode t)
{
	return t?t->sum:0;
}
void upz(pnode t)
{
	if(!t)return;
	t->size=sz(t->l)+sz(t->r)+1;
	t->sum=sm(t->l)+t->val+sm(t->r);
	t->M=t->L=t->R=t->val;
	int LL,LR,RR,RL,ML,MR;
	if(t->l)LL=t->l->L,LR=t->l->R,ML=t->l->M;
	else LL=0,LR=0,ML=-MI;
	if(t->r)RR=t->r->R,RL=t->r->L,MR=t->r->M;
	else RR=0,RL=0,MR=-MI;
	t->L=max(LL,sm(t->l)+t->val+RL);
	t->R=max(RR,sm(t->r)+t->val+LR);
	t->M=max(ML,MR,t->val+RL+LR);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
	if(!t)
	{
		r=l=NULL;return;
	}
	int cpos=add+sz(t->l);
	if(cpos<pos) split(t->r,t->r,r,pos,cpos+1),l=t;
	else split(t->l,l,t->l,pos,add),r=t;
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
void insert(pnode &t,int key,int val)
{
	pnode l,r,md,it;
	split(t,l,r,key-1);
	it=new node(val);
	merge(t,l,it);
	merge(t,t,r);
}
void erase(pnode &t,int key)
{
	pnode l,r,md;
	split(t,l,r,key);
	split(l,l,md,key-1);
	delete md;
	merge(t,l,r);
}
void replace(pnode &t,int key,int val)
{
	erase(t,key);
	insert(t,key,val);
}
int query(pnode &t,int fs,int ls)
{
	pnode l,r,md;
	int ret;
	split(t,l,r,ls);
	split(l,l,md,fs-1);
	ret=md->M;
	merge(t,l,md);
	merge(t,t,r);
	return ret;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	srand(135);
	int i,j,k,Q,n,a,b;
	char ch[3];
	scanf("%d",&n);
	pnode root=NULL,it;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&j);
		it=new node(j);
		merge(root,root,it);
		// printf("%d %d\n",query(root,1,i),root->M);
	}
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%s",ch);
		switch(ch[0])
		{
		case 'I':
			scanf("%d %d",&a,&b);
			insert(root,a,b);
			break;
		case 'D':
			scanf("%d",&a);
			erase(root,a);
			break;
		case 'R':
			scanf("%d %d",&a,&b);
			replace(root,a,b);
			break;
		case 'Q':
			scanf("%d %d",&a,&b);
			printf("%d\n",query(root,a,b));
		}
	}
}