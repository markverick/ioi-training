#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ft[3][1000135];
void add(int x,int val,int t)
{
	x++;
	while(x<=1000005)
	{
		ft[t][x]+=val;
		x+=x&-x;
	}
}
int sum(int x,int t)
{
	x++;
	int sm=0;
	while(x>0)
	{
		sm+=ft[t][x];
		x-=x&-x;
	}
	return sm;
}
void app(pair<int,int> *x,int a)
{
	x->X=min(x->X,a);
	x->Y=max(x->Y,a);
}
void clr(pair<int,int> *x)
{
	x->X=MI;x->Y=-MI;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,a,b,Q;
	pair<int,int> mx={MI,-MI},my={MI,-MI};
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		clr(&mx);
		clr(&my);
		for(j=1;j<=3;j++)
		{
			scanf("%d %d",&a,&b);
			app(&mx,a);
			app(&my,b);
		}
		add(mx.X+1,1,0);
		add(mx.Y,-1,0);
		add(my.X+1,1,1);
		add(my.Y,-1,1);
		// printf("%d - %d | %d - %d\n",mx.X,mx.Y,my.X,my.Y);
	}
	scanf("%d",&Q);
	char ch[3];
	while(Q--)
	{
		scanf("%s %*s %d",ch,&a);
		if(ch[0]=='x')
			printf("%d\n",sum(a,0));
		else
			printf("%d\n",sum(a,1));
	}
}