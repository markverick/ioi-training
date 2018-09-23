#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,a,b,c,d;
	for(i=4;i<=7;i++)
	{
		scanf("%d",&n);
		for(j=1;j<=n;j++)
		{
			scanf("%d %d %d",&a,&b,&c);
			printf("v[%d].EB(%d,%d,vector<int> {",i,a,b);
			for(k=1;k<=c;k++)
			{
				scanf("%d",&d);
				if(k!=1)printf(",");
				printf("%d",d);
			}
			printf("});");
			printf("\n");
		}
	}
}