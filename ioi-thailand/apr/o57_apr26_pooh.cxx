#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int jum[3135][3135],hsh[3135][3135];
int dp(int x,int y)
{
	if(jum[x][y]>=0)return jum[x][y];
	if(x==1&&y==1)
	{
		return 0;
	}
	int mc=0;
	if(x-1>=1)
		mc=max(mc,dp(x-1,y)+hsh[x-1][y]);
	if(y-1>=1)
		mc=max(mc,dp(x,y-1)+hsh[x][y-1]);
	return jum[x][y]=mc;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,r,c,a,b;
	memset(jum,-1,sizeof jum);
	scanf("%d %d %d",&r,&c,&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		a++;b++;
		hsh[a][b]++;
	}
	printf("%d\n",dp(r,c)+hsh[r][c]);
}