#include<bits/stdc++.h>
using namespace std;
int tx,ty;
int dp(int a,int b,int x,int y)
{
	int mc=0,i,j;
	for(i=1;i<=a*(a+1)/2;i++)
	{
		if(x+i<=tx&&y+b+1<=ty)
			mc=max(mc,dp(i,b+1,x+i,y+b+1)+1);
	}
	for(i=1;i<=b;i++)
	{
		if(x+a+1<=tx&&y+i<=ty)
			mc=max(mc,dp(a+1,i,x+a+1,y+i)+1);
	}

	return mc;
}
int main()
{
	int i,j,k,T,t;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d %d",&tx,&ty);
		printf("%d\n",max(dp(1,0,1,0),dp(0,1,0,1)));
	}
}