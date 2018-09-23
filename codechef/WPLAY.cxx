#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[20],d[500135][20];
int r,c;
int jum[70135],id[70135];
typedef class node
{
public:
	node* adj[27];
	char c=0;
	int head=0;
	node(char t)
	{
		for(int i=0;i<26;i++)
			adj[i]=NULL;
		c=t;
	}
} node;
typedef node* pnode;
pnode root;
int dp(int bit);
int gen(int bit,int pro,int ori,pnode t)
{
	int i=pro&-pro,mn;
	if(!pro)
	{
		if(t->head)
			return dp(bit);
		return 1;
	}
	mn=gen(bit,pro-i,ori,t);
	if(t->adj[s[id[i]]-'A'])
		return mn&gen(bit-i,pro-i,ori,t->adj[s[id[i]]-'A']);
	return mn;
}
int dp(int bit)
{
	// printf("%d\n",bit);
	if(jum[bit]>=0)return jum[bit];
	return jum[bit]=1-gen(bit,bit,bit,root);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,T,len,bit,L,R;
	for(i=0;i<16;i++)
		id[1<<i]=i;
	scanf("%d",&n);
	root=new node(0);
	pnode t;
	for(i=1;i<=n;i++)
	{
		scanf("%s",d[i]);
		len=strlen(d[i]);
		sort(&d[i][0],&d[i][len]);
		t=root;
		for(j=0;j<len;j++)
		{
			if(t->adj[d[i][j]-'A']==NULL)
				t->adj[d[i][j]-'A']=new node(d[i][j]);
			t=t->adj[d[i][j]-'A'];
		}
		t->head=1;
		// printf("%s\n",d[i]);
	}

	scanf("%d %d",&r,&c);
	scanf("%d",&T);
	while(T--)
	{
		for(i=0;i<(1<<(r*c));i++)
			jum[i]=-1;
		for(i=0;i<r;i++)
		{
			scanf("%s",s+c*i);
		}
		sort(&s[0],&s[r*c]);
		if(dp((1<<(r*c))-1))
			printf("Alice\n");
		else
			printf("Bob\n");
		// printf("%d\n",dp((1<<(r*c))-1))
	}
}