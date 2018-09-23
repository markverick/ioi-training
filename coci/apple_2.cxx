#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[531][531];
int L[531][531],R[531][531];
int dist(int x,int y)
{
	return x*x+y*y;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int mn=MI;
	int r,c,n,i,j,k,x,y;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
		scanf("%s",s[i]+1);
	for(i=1;i<=r;i++)
	{
		k=-12345;
		for(j=1;j<=c;j++)
		{
			if(s[i][j]=='x')
				k=j;
			L[i][j]=k;
		}
		k=12345;
		for(j=c;j>=1;j--)
		{
			if(s[i][j]=='x')
				k=j;
			R[i][j]=k;
		}
	}
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&x,&y);
		mn=MI;
		for(j=1;j<=r;j++)
		{
			mn=min(mn,dist(abs(j-x),min(y-L[j][y],R[j][y]-y)));
		}
		printf("%d\n",mn);
		s[x][y]='x';
		k=-12345;
		for(j=1;j<=c;j++)
		{
			if(s[x][j]=='x')
				k=j;
			L[x][j]=k;
		}
		k=12345;
		for(j=c;j>=1;j--)
		{
			if(s[x][j]=='x')
				k=j;
			R[x][j]=k;
		}
	}
}