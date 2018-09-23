#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int a[100135],x,mp[100135];
pair<int,int> b[100135];
typedef class node
{
public:
	node *l=NULL,*r=NULL;
	int s=1;
}node;
typedef node* pnode;
pnode root[100135];
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
int kth(pnode L,pnode R,int fs,int ls,int key)
{
	if(fs==ls)
		return a[b[fs].Y];
	int md=(fs+ls)/2;
	int l=R->l->s-L->l->s;
	if(key<=l)
		return kth(L->l,R->l,fs,md,key);
	else
		return kth(L->r,R->r,md+1,ls,key-l);
}
int main()
{
	int n,i,j,k,m,L,R;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		b[i]=MP(a[i],i);
	}
	sort(&b[1],&b[n+1]);
	for(i=1;i<=n;i++)
		mp[b[i].Y]=i;
	build(root[0],1,n);
	for(i=1;i<=n;i++)
	{
		x=mp[i];
		root[i]=update(root[i-1],1,n);
	}
	while(m--)
	{
		scanf("%d %d %d",&L,&R,&x);
		printf("%d\n",kth(root[L-1],root[R],1,n,x));
	}
}