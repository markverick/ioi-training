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
	int val,size,prior;
	node *l,*r;
	node(int v)
	{
		val=v;size=1;prior=rand()*(1<<15)+rand();l=r=NULL;
	}
}node;
typedef node* pnode;
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
void insert(pnode &t,int key)
{
	pnode l,r,md,it;
	split(t,l,r,key);
	split(l,l,md,key-1);
	if(!md)it=new node(key);
	else it=md;
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
int kth(pnode t,int key)
{
	if(!t)
		return -MI;
	else if(key==sz(t->l)+1)
		return t->val;
	else if(key<sz(t->l)+1)
		return kth(t->l,key);
	else
		return kth(t->r,key-sz(t->l)-1);
}
int count(pnode t,int key)
{
	if(!t) return 0;
	else if(t->val<key) return count(t->r,key)+sz(t->l)+1;
	else return count(t->l,key);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	srand(135);
	int i,j,k,Q,x;
	char ch[3];
	scanf("%d",&Q);
	pnode root=NULL;
	while(Q--)
	{
		scanf("%s %d",ch,&x);
		if(ch[0]=='I')
		{
			insert(root,x);
		}
		else if(ch[0]=='D')
		{
			erase(root,x);
		}
		else if(ch[0]=='K')
		{
			j=kth(root,x);
			if(j==-MI)
				printf("invalid\n");
			else
				printf("%d\n",j);
		}
		else
		{
			printf("%d\n",count(root,x));
		}
		// printf("\t%d\n",root->order);
	}
}