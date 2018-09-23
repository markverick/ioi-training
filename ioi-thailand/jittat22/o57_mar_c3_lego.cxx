#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int readInt()
{
	bool minus=false;
	int result=0;
	char ch;
	ch=getchar();
	while(true)
	{
		if(ch=='-')break;
		if(ch>='0'&&ch<='9')break;
		ch=getchar();
	}
	if(ch=='-')minus=true; else result=ch-'0';
	while(true){
		ch=getchar();
		if(ch<'0'||ch>'9')break;
		result=result*10+(ch-'0');
	}
	if(minus)
		return -result;
	else
		return result;
}
typedef struct node
{
	node *l=NULL,*r=NULL;
	int val,prior=rand()*32768+rand(),size=1;
	node(int v)
	{
		val=v;
	}
} node;
typedef node* pnode;
inline int sz(pnode t)
{
	return t?t->size:0;
}
inline void upz(pnode &t)
{
	if(t)t->size=sz(t->l)+sz(t->r)+1;
}
inline void split(pnode t,pnode &l,pnode &r,int pos,int add=0)
{
	if(!t){l=r=NULL;return;}
	int cpos=sz(t->l)+add;
	if(pos>cpos) split(t->r,t->r,r,pos,cpos+1),l=t;
	else split(t->l,l,t->l,pos,add),r=t;
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
inline void cut(pnode &t,int L,int R,int pos)
{
	pnode fs,md,ls,md2;
	split(t,md,ls,R);
	split(md,fs,md,L-1);
	if(pos<=sz(fs))
	{
		split(fs,fs,md2,pos);///fs - md2 - md - fs => fs md md2 ls
		merge(fs,fs,md);
		merge(ls,md2,ls);
		merge(t,fs,ls);
	}
	else
	{
		split(ls,md2,ls,pos-sz(fs)-sz(md)); //fs - md - md2 - ls => fs - md2 - md - ls
		merge(fs,fs,md2);
		merge(ls,md,ls);
		merge(t,fs,ls);
	}
}
inline int find(pnode t,int key)
{
	if(key==sz(t->l)+1)
		return t->val;
	else if(key<=sz(t->l))
		return find(t->l,key);
	return find(t->r,key-sz(t->l)-1);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	srand(999);
	int n,m,i,j,k,ch,x,l,y,a;
	pnode root=NULL,t;
	n=readInt();
	m=readInt();
	for(i=1;i<=n;i++)
	{
		a=readInt();
		merge(root,root,new node(a));
	}
	while(m--)
	{
		ch=readInt();
		if(ch==1)
		{
			x=readInt();
			l=readInt();
			y=readInt();
			cut(root,x,x+l-1,y-1);
		}
		else
		{
			x=readInt();
			printf("%d\n",find(root,x));
		}
	}
}