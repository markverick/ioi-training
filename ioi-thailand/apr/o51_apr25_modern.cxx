#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m,c,jum[505][505][3][33];
int dp(int x,int y,int sd,int num)
{
	int sm=0;
	if(jum[x][y][sd][num]>=0)return jum[x][y][sd][num];
	if(x==n&&y==m)
		return 1;
	// if(num==c)return 0;
	if(sd==0)
	{
		if(x+1<=n&&y+1<=m) sm+=dp(x+1,y+1,0,1)*(c-1);
		if(x+1<=n) sm+=dp(x+1,y,1,2)*(c-1);
		if(y+1<=m) sm+=dp(x,y+1,2,2)*(c-1);
	}
	else if(sd==1)
	{
		if(x+1<=n&&y+1<=m) sm+=dp(x+1,y+1,0,1)*(c-num);
		if(x+1<=n&&num+1<=c) sm+=dp(x+1,y,1,num+1)*(c-num);
		if(x+1<=n) sm+=dp(x+1,y,1,num)*(num-1);
		if(y+1<=m) sm+=dp(x,y+1,2,2)*(c-num);
	}
	else
	{
		if(x+1<=n&&y+1<=m)sm+=dp(x+1,y+1,0,1)*(c-num);
		if(y+1<=m&&num+1<=c)sm+=dp(x,y+1,2,num+1)*(c-num);
		if(y+1<=m)sm+=dp(x,y+1,2,num)*(num-1);
		if(x+1<=n)sm+=dp(x+1,y,1,2)*(c-num);
	}
	sm%=2011;
	return jum[x][y][sd][num]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,sm=0;
	memset(jum,-1,sizeof jum);
	scanf("%d %d %d",&n,&m,&c);
	for(i=1;i<=n;i++)
		sm+=dp(i,1,0,1)*c,sm%=2011;
	for(i=2;i<=m;i++)
		sm+=dp(1,i,0,1)*c,sm%=2011;
	printf("%d\n",sm%2011);
}