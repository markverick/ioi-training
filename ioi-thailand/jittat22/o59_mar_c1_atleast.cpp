#include<bits/stdc++.h>
#define MI 100135
#define EPS 0.0000000001
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
	int size=0;
	double avg=0;
	node(int v){l=r=NULL;avg=v;size=1;}
	node(){l=r=NULL;avg=0;size=0;}
}node;
typedef node* pnode;
vector<pair<int,int> > v; 
int a[100135];
map<int,int> mp;
int sz(pnode t){return t?t->size:0;}
double av(pnode t){return t?t->avg:0;}
pnode id[100135];
void upd(pnode &t)
{
	if(!t)return;
	t->size=sz(t->l)+sz(t->r);
	t->avg=(av(t->l)*sz(t->l)+av(t->r)*sz(t->r))/t->size;
}
pnode build(int fs,int ls)
{
	int md=(fs+ls)/2;
	if(fs==ls)
		return new node();
	pnode t=new node();
	t->l=build(fs,md);
	t->r=build(md+1,ls);
	return t;
}
pnode add(pnode t,int x,int fs,int ls)
{
	if(fs==ls)
		return new node(v[x].X);
	int md=(fs+ls)/2;
	pnode it=new node();
	it->l=t->l;it->r=t->r;
	if(x<=md)
		it->l=add(t->l,x,fs,md),it->r=t->r;
	else
		it->r=add(t->r,x,md+1,ls),it->l=t->l;
	upd(it);
	return it;
}
int x,y;
int sum(pnode s,pnode t,double key,pair<double,int> ri,int fs,int ls)
{
	int md=(fs+ls)/2;
	double avg,rj;
	// printf("%d <- %d -> %d\n",fs,md,ls);
	if(fs==ls)
	{
		if(!sz(t)||sz(s))return 0;
		return (av(t)+ri.X*ri.Y)/(ri.Y+1)<key;
	}
	int size=sz(t->r)-sz(s->r);
	if(size)
		avg=(av(t->r)*sz(t->r)-av(s->r)*sz(s->r))/size;
	else
		avg=ri.X;
	if(ri.Y+size==0)return MI;
	rj=(avg*size+ri.X*ri.Y)/(ri.Y+size);
	// printf("%f\n",rj);
	if(size&&key>rj+EPS)
		return sum(s->r,t->r,key,ri,md+1,ls)+sz(t->l)-sz(s->l);
	else
		return sum(s->l,t->l,key,MP(rj,ri.Y+size),fs,md);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,out;
	vector<int> u;
	double sm,avg;
	pnode root=NULL;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		v.emplace_back(a[i],i);
	}
	sort(v.begin(),v.end());
	// v.resize(unique(v.begin(),v.end())-v.begin());
	u.resize(v.size());
	for(i=0;i<v.size();i++)
		u[v[i].Y]=i;
	id[0]=build(0,v.size()-1);
	for(i=1;i<=n;i++)
	{
		id[i]=add(id[i-1],u[i],0,v.size()-1);
	}
	while(m--)
	{
		scanf("%d %d %lf",&x,&y,&sm);
		out=sum(id[x-1],id[y],sm,MP(0,0),0,v.size()-1);
		if(out<100135)
			printf("%d\n",out);
		else
			printf("-1\n");
		// printf("%d-%d - %d\n",sz(id[y]),sz(id[x-1]),sum(id[x-1],id[y],sm,MP(0,0),0,v.size()-1));
	}
}