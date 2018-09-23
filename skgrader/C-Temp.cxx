#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[135][135],b[135][135];
int dx[5]={1,-1,0,0};
int dy[5]={0,0,1,-1};
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int r,c,i,j,k,cot=0,sm;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
		{
			// printf("%d\n",a[i][j]);
			if(a[i][j]!=0)
			{
				b[i][j]=a[i][j];
				continue;
			}
			cot=0;sm=0;
			for(k=0;k<4;k++)
			{
				if(a[i+dx[k]][j+dy[k]]!=0)
					cot++,sm+=a[i+dx[k]][j+dy[k]];
			}
			if(cot>0) b[i][j]=sm/cot;
			else b[i][j]=0;
		}
	}
	for(i=1;i<=r;i++)
	{
		for(j=1;j<=c;j++)
			printf("%d ",b[i][j]);
		printf("\n");
	}
}