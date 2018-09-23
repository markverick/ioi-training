#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long rx(long long x)
{
	long long res[]={x,1,x+1,0};
	return res[x%4];
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,x=0,a,b;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d %I64d",&a,&b);
		x^=rx(a-1);
		x^=rx(a+b-1);
	}
	if(x)
		printf("tolik");
	else
		printf("bolik");
}