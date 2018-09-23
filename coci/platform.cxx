#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
pair<int,pair<int,int> > p[135];
int h[10135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&p[i].X,&p[i].Y.X,&p[i].Y.Y);
	}
	sort(&p[1],&p[n+1]);
	for(i=1;i<=n;i++)
	{
		sum+=p[i].X-h[p[i].Y.X];
		sum+=p[i].X-h[p[i].Y.Y-1];
		for(j=p[i].Y.X;j<p[i].Y.Y;j++)
		{
			h[j]=p[i].X;
		}
	}
	printf("%d",sum);
	
}