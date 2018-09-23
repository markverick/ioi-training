#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[12];
int n;
int ty(int x,int y)
{
	if(x<1||x>n||y<1||y>n)return 0;
	printf("examine %d %d\n",x,y);
	fflush(stdout);scanf("%s",s);
	if(s[0]=='t')return 1;
	return 0;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,fs,md,ls,mc,x,y,mn;
	pair<int,int> r,c;
	pair<int,int> R={MI,0},C={MI,0};
	scanf("%d %d %d",&n,&x,&y);
	for(i=0;i<=n;i++)
	{
		j=(1<<i);
		if(ty(x+j,y))
			x+=j;
		else
			break;
	}
	j/=2;
	while(j>0)
	{
		if(ty(x+j,y))
			x+=j;
		j/=2;
	}
	r.Y=x;
	for(i=0;i<=n;i++)
	{
		j=(1<<i);
		if(ty(x-j,y))
			x-=j;
		else
			break;
	}
	j/=2;
	while(j>0)
	{
		if(ty(x-j,y))
			x-=j;
		j/=2;
	}
	r.X=x;
	for(i=0;i<=n;i++)
	{
		j=(1<<i);
		if(ty(x,y+j))
			y+=j;
		else
			break;
	}
	j/=2;
	while(j>0)
	{
		if(ty(x,y+j))
			y+=j;
		j/=2;
	}
	c.Y=y;
	for(i=0;i<=n;i++)
	{
		j=(1<<i);
		if(ty(x,y-j))
			y-=j;
		else
			break;
	}
	j/=2;
	while(j>0)
	{
		if(ty(x,y-j))
			y-=j;
		j/=2;
	}
	c.X=y;
	int w=r.Y-r.X+1;
	x=(r.Y+r.X)/2;
	y=(c.Y+c.X)/2;
	while(135)
	{
		if(ty(x-w*2,y))
			x-=w*2;
		else
			break;
	}
	while(135)
	{
		if(ty(x,y-w*2))
			y-=w*2;
		else
			break;
	}
	if(ty(x+w*4,y))
		printf("solution %d %d\n",x+w*2,y+w*2);
	else
		printf("solution %d %d\n",x+w,y+w);
		
	fflush(stdout);
}