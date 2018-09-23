#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ft[2][401135],hsh[401135];
void add(int x,int val,int t)
{
	x+=100005;
	while(x<=400100)
	{
		ft[t][x]+=val;
		x+=x&-x;
	}
}
int sum(int x,int t)
{
	int sm=0;
	x+=100005;
	while(x>0)
	{
		sm+=ft[t][x];
		x-=x&-x;
	}
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,l,i,j,k,t,x,d,ch;
	scanf("%d %d",&n,&l);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&ch);
		if(ch==1)
		{
			scanf("%d %d %d",&t,&x,&d);
			x+=100005;
			add(x-t,d,0);
			add(x+t,d,1);
			hsh[x]+=d;
		}
		else
		{
			scanf("%d %d",&t,&x);
			x+=100005;
			printf("%d\n",sum(x,0)-sum(x-t-1,0)/*+sum(x,1)-sum(x-t-1,1)-hsh[x]*/);
			printf("%d\n",sum(x,1)-sum(x-t-1,1));
			printf("%d\n",sum(x,0)-sum(x-t-1,0)/*+sum(x,1)-sum(x-t-1,1)-hsh[x]*/);
		}
	}
}