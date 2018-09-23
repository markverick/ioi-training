#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[1000135],id[1000135];
long long ft[1000135],qs[1000135];
pair<long long,long long> p[1000135];
void add(long long x,long long val)
{
	x++;
	while(x<=1000005)
	{
		ft[x]+=val;
		x+=x&-x;
	}
}
long long sum(long long x)
{
	x++;
	long long sm=0;
	while(x>0)
	{
		sm+=ft[x];
		x-=x&-x;
	}
	return sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	// freopen("in.txt","r",stdin);
	long long n,i,j,k,m;
	long long sm=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%lld",&m);
	for(i=1;i<=n;i++)
		a[i]-=m;
	for(i=1;i<=n;i++)
	{
		qs[i]=qs[i-1]+a[i];
		p[i]=MP(-qs[i],i);
	}
	sort(&p[0],&p[n+1]);
	j=1;
	id[p[0].Y]=j;
	for(i=1;i<=n;i++)
	{
		if(p[i].X!=p[i-1].X)
			j++;
		id[p[i].Y]=j;
	}
	// for(i=1;i<=n;i++)
	// {
	// 	printf("%lld %lld\n",qs[i],id[i]);
	// }
	// printf("%lld\n",id[0]);
	for(i=1;i<=n;i++)
	{
		add(id[i-1],1);
		sm+=i-sum(id[i]-1);
	}
	printf("%lld",sm);
}