#include<bits/stdc++.h>
#define MI 1000000000
#define BD 10005
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[1135],y[1135];
vector<int> v;
int main()
{
	// freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,a,b;
	while(scanf("%d",&n))
	{
		if(n==0)return 0;
		for(i=1;i<=n;i++)
		{
			scanf("%d %d",&x[i],&y[i]);
		}
		x[n+1]=x[1];y[n+1]=y[1];
		scanf("%d %d",&a,&b);
		j=0;
		for(i=1;i<=n;i++)
		{
			if(x[i]==x[i+1])
			{
				if(y[i]>y[i+1])swap(y[i],y[i+1]);
				if(b>=y[i]&&b<=y[i+1]&&x[i]<a)
					j++;
			}
		}
		if(j%2)printf("T\n");
		else printf("F\n");
	}
}