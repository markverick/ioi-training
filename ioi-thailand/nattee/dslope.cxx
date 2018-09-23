#include<bits/stdc++.h>
#define MI 1000000000
#define M 999999999
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,m,ft[44][80135],a[80135];
void add(long long x,long long val,long long t)
{
	while(x<=n+4)
	{
		ft[t][x]+=val;
		ft[t][x]%=M;
		x+=x&-x;
	}
}
long long sum(long long x,long long t)
{
	long long sm=0;
	while(x>0)
	{
		sm+=ft[t][x];
		sm%=M;
		x-=x&-x;
	}
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k;
	scanf("%lld %lld",&n,&m);
	for(i=n;i>=1;i--)
		scanf("%lld",&a[i]);
	for(i=1;i<=n;i++)
	{
		for(j=m;j>=2;j--)
		{
			k=sum(a[i],j-1);
			add(a[i],k,j);
		}
		add(a[i],1,1);
	}
	printf("%lld",sum(n,m));
}