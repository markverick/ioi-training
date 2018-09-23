#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[55],b[55];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		x=0;y=0;
		if(n==0)return 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
		}
		a[n+1]=a[1];b[n+1]=b[1];
		a[n+2]=a[2];b[n+2]=b[2];
		for(i=1;i<=n;i++)
		{
			if((a[i+1]-a[i])*(b[i+2]-b[i])-(a[i+2]-a[i])*(b[i+1]-b[i])>=0)
				x=1;
			else
				y=1;
		}
		// printf("%d %d\n",x,y);
		if(x^y)
			printf("No\n");
		else
			printf("Yes\n");
	}
}