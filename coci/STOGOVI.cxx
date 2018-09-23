#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int p[21][300135],a[300135],b[300135],h[300135],ori[300135];
typedef class node
{
public:
	node *p=NULL,*ori=NULL;
	int val=0,h=0;
	node(node *x)
	{
		p=x;
		
	}
} node;
typedef node* pnode;
pnode pos[300135];
char ch[3];
void add(int idx,pnode x)
{
	pnode it=new node(x);
	it->ori=it;
	it->val=idx;
	it->h=x->h+1;
	pos[idx]=it;
}
void append(int idx,pnode x)
{
	pnode it=new node(x);
	it->ori=x->ori;
	it->val=x->val;
	it->h=x->h;
	pos[idx]=it;
}
int Dif(int a,int b) //Find LCA's height
{
	int i;
	if(h[a]<h[b])swap(a,b);
	for(i=20;i>=0;i--)
		if(h[p[i][a]]>=h[b])
			a=p[i][a];
	if(a==b)
		return h[a];
	for(i=20;i>=0;i--)
		if(p[i][a]!=p[i][b])
			a=p[i][a];b=p[i][b];
	return h[a]-1;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,v,w;
	scanf("%d",&n);
	pnode root=new node(NULL);
	root->ori=root;
	root->p=root;
	pos[0]=root;
	vector<int> out;
	for(i=1;i<=n;i++)
	{
		scanf("%s %d",&ch,&v);
		if(ch[0]=='a')
		{
			add(i,pos[v]);
		}
		else if(ch[0]=='b')
		{
			append(i,pos[v]->ori->p);
			out.emplace_back(pos[v]->ori->val);
		}
		else
		{
			scanf("%d",&w);
			append(i,pos[v]);
			out.emplace_back(-i);
			a[i]=v;b[i]=w;
		}
	}
	p[0][0]=0;
	for(i=1;i<=n;i++)
	{
		p[0][i]=pos[i]->ori->p->val;
		h[i]=pos[i]->h;
		ori[i]=pos[i]->ori->val;
	}
	for(i=1;i<=20;i++)
		for(j=1;j<=n;j++)
			p[i][j]=p[i-1][p[i-1][j]];
	for(i=0;i<out.size();i++)
	{
		if(out[i]>=0)
			printf("%d\n",out[i]);
		else
			printf("%d\n",Dif(ori[a[-out[i]]],ori[b[-out[i]]]));
	}
}