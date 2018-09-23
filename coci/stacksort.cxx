#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
//x = push, y = pop, ch = last choice,
int jum[55][55][4][55];
int dp(int x,int y,int ch,int num)
{
	if(jum[x][y][ch][num]>=0)
		return jum[x][y][ch][num];
	int i,j,sm=0;
	// printf("%d %d %d %d\n",x,y,ch,num);
	if(x+y==0)
	{
		if(num==0)
			return 1;
		return 0;
	}
	if(y)
		sm+=dp(x,y-1,1,num);
	if(x>y)
	{
		if(ch==1)
			sm+=dp(x-1,y,0,num);
		else if(num)
			sm+=dp(x-1,y,0,num-1);
	}
	return jum[x][y][ch][num]=sm%2009;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	memset(jum,-1,sizeof jum);
	int Q,i,j,k,n,m;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d %d",&n,&m);
		printf("%d\n",dp(n,n,2,m));
	}
}