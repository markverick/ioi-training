#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[55][55],mapsr[55][55],qs[55][55],hsh[5000135];
int sum(int a,int b,int c,int d)
{
	return qs[c][d]-qs[a-1][d]-qs[c][b-1]+qs[a-1][b-1];
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,l,sm=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			scanf("%d",&maps[i][j]);
			mapsr[n-j+1][i]=maps[i][j];
			qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+maps[i][j];
		}
	}
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			for(k=1;k<=i;k++)
			{
				for(l=1;l<=j;l++)
				{
					hsh[sum(k,l,i,j)+2500000]++;
				}
			}
			for(k=i+1;k<=n;k++)
			{
				for(l=j+1;l<=n;l++)
				{
					sm+=hsh[sum(i+1,j+1,k,l)+2500000];
				}

			}
			for(k=1;k<=i;k++)
			{
				for(l=1;l<=j;l++)
				{
					hsh[sum(k,l,i,j)+2500000]--;
				}
			}
		}
	}
	// printf("%d\n",sm);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			maps[i][j]=mapsr[i][j],qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+mapsr[i][j];
	// for(i=1;i<=n;i++)
	// {
	// 	for(j=1;j<=n;j++)
	// 	{
	// 		printf("%d",maps[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			for(k=1;k<=i;k++)
			{
				for(l=1;l<=j;l++)
				{
					hsh[sum(k,l,i,j)+2500000]++;
				}
			}
			for(k=i+1;k<=n;k++)
			{
				for(l=j+1;l<=n;l++)
				{
					sm+=hsh[sum(i+1,j+1,k,l)+2500000];
				}

			}
			for(k=1;k<=i;k++)
			{
				for(l=1;l<=j;l++)
				{
					hsh[sum(k,l,i,j)+2500000]--;
				}
			}
		}
	}
	printf("%d\n",sm);
}