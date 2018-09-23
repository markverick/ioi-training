#include<bits/stdc++.h>
#define MI 10000000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long qs[4][305][305],ms[4][305][305],a[311][311];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long r,c,i,j,k,mc=-MI,l,mac,mak;
	scanf("%lld %lld",&r,&c);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			scanf("%lld",&a[i][j]);
		}
	}
	for(i=0;i<=r+1;i++)
		for(j=0;j<=c+1;j++)
			for(k=0;k<4;k++)
				ms[k][i][j]=-MI;
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			qs[0][i][j]=a[i][j]+qs[0][i-1][j]+qs[0][i][j-1]-qs[0][i-1][j-1],ms[0][i][j]=max(qs[0][i][j],max(ms[0][i][j-1],ms[0][i-1][j]));
	for(i=1;i<=r;i++)
		for(j=c;j>=1;j--)
			qs[1][i][j]=a[i][j]+qs[1][i-1][j]+qs[1][i][j+1]-qs[1][i-1][j+1],ms[1][i][j]=max(qs[1][i][j],max(ms[1][i][j+1],ms[1][i-1][j]));
	for(i=c;i>=1;i--)
		for(j=1;j<=c;j++)
			qs[2][i][j]=a[i][j]+qs[2][i+1][j]+qs[2][i][j-1]-qs[2][i+1][j-1],ms[2][i][j]=max(qs[2][i][j],max(ms[2][i][j-1],ms[2][i+1][j]));
	for(i=r;i>=1;i--)
		for(j=c;j>=1;j--)
			qs[3][i][j]=a[i][j]+qs[3][i+1][j]+qs[3][i][j+1]-qs[3][i+1][j+1],ms[3][i][j]=max(qs[3][i][j],max(ms[3][i][j+1],ms[3][i+1][j]));
	// for(k=0;k<4;k++)
	// {
	// 	for(i=1;i<=r;i++)
	// 	{
	// 		for(j=1;j<=c;j++)
	// 		{
	// 			printf("%lld ",ms[k][i][j]);
	// 		}
	// 		printf("\n");
	// 	}
	// 	printf("\n");
	// }
	mc=-MI;
	for(i=1;i<r;i++)
	{
		for(j=i+1;j<r;j++)
		{
			mac=-MI;
			for(k=1;k<c;k++)
			{
				mac=max(mac,ms[2][i+1][k]+ms[3][j+1][k+1]);
				mc=max(mc,ms[0][i][k]+ms[1][j][k+1]+mac);
			}
		}
	}
	// printf("%lld\n",mc);
	for(i=1;i<r;i++)
	{
		for(j=i+1;j<r;j++)
		{
			mac=-MI;
			// printf("%lld %lld\n",j,i);
			for(k=c;k>0;k--)
			{
				mac=max(mac,ms[3][i+1][k]+ms[2][j+1][k-1]);
				mc=max(mc,ms[1][i][k]+ms[0][j][k-1]+mac);
				// printf("%lld! (%lld+%lld) + %lld\n",k,ms[0][j][k-1],ms[1][i][k],mac);
			}
		}
	}
	for(i=1;i<r;i++)
	{
		mac=-MI;mak=-MI;
		for(j=1;j<c;j++)
		{
			mac=max(mac,ms[0][i][j]+ms[1][i][j+1]);
			mak=max(mak,ms[2][i+1][j]+ms[3][i+1][j+1]);
		}
		mc=max(mc,mak+mac);
	}
	printf("%lld",mc);
}