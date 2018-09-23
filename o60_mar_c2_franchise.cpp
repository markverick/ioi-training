#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1005],L[1005][33][33],R[1005][33][33];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,o;
	scanf("%d %d %d",&n,&o,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		L[i][0][1]=a[i];
		for(j=1;j<=o;j++)
		{
			for(k=0;k<=m;k++)
			{
				L[i][j][k]=max(L[i-1][j-1][k-1]+a[i],L[i-1][j-1][k]);
			}
		}
	}
	for(i=n;i>=1;i--)
	{
		R[i][0][1]=a[i];
		for(j=1;j<=o;j++)
		{
			for(k=0;k<=m;k++)
			{
				R[i][j][k]=max(L[i-1][j-1][k-1]+a[i],L[i-1][j-1][k]);
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=o;j++)
		{
			for(k=0;k<=m;k++)
			{
				for(l=0;l<=k;l++)
					mc=max(mc,L[i][j][k]+R[i][o-j][k])
				
			}
		}
	}
}