#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
map<int,int> mp;
int key,val,lft[100135];
tuple<int,int,int> p[100135],q[100135];
vector<int> v;
typedef struct node
{
	node *l=NULL,*r=NULL;
	int sum=0;
	node(int val)
	{
		sum=val;
	}
} node;
typedef node* pnode;
pnode root[100135];
void build(pnode &t,int fs,int ls)
{
	t=new node(0);
	if(fs==ls)
		return;
	int md=(fs+ls)/2;
	build(t->l,fs,md);
	build(t->r,md+1,ls);
}
pnode add(pnode t,int fs,int ls)
{
	if(fs==ls)
	{
		return new node(t->sum+1);
	}
	int md=(fs+ls)/2;
	pnode it=new node(0);
	*it=*t;
	if(key<=md)
		it->l=add(t->l,fs,md);
	else
		it->r=add(t->r,md+1,ls);
	it->sum=it->l->sum+it->r->sum;
	return it;
}
int sum(pnode t,int fs,int ls)
{
	int md=(fs+ls)/2;
	if(ls<key)return 0;
	if(fs>=key)return t->sum;
	return sum(t->l,fs,md)+sum(t->r,md+1,ls);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,x,y,z,sm=0;
	val=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		p[i]=MT(x,y,z);
		v.emplace_back(x);
		v.emplace_back(y);
		v.emplace_back(z);
	}
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(i=0;i<v.size();i++)
		mp[v[i]]=i;
	sort(&p[1],&p[n+1]);
	build(root[n+1],0,v.size()-1);
	j=n;
	for(i=n-1;i>=1;i--)
	{
		tie(x,y,z)=p[i];
		if(get<0>(p[i+1])!=x)
		{
			for(k=j;k>i;k--)
			{
				key=y;
				root[k]=add(root[k+1],0,v.size()-1);
			}
			x
		}
	}
}