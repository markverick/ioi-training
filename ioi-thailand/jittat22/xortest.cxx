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
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);

	printf("%d\n",10&(-10));
	int n,i,j,k,x=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		x^=i;
		printf("%d %d\n",i,x);
	}
}