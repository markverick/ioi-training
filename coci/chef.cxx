#include<bits/stdc++.h>
#define MI 1000000000ll
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long x[135],y[135],s1[135],s2[135],p1[135],p2[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n,m,fs,md,ls,mc=0,sum=0,lo;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld %lld %lld %lld",&x[i],&y[i],&s1[i],&p1[i],&s2[i],&p2[i]);
	}
	fs=0;ls=100000;//7 digit
	while(fs<=ls)
	{
		md=(fs+ls)/2;
		sum=0;
		for(i=1;i<=n;i++)
		{
			k=md*x[i]-y[i];lo=MI*MI;
			for(j=0;j*s2[i]<=k+s2[i];j++)
			{
				lo=min(lo,j*p2[i]+max(0ll,((k-j*s2[i]+s1[i]-1)/s1[i])*p1[i]));
			}
			sum+=lo;
			if(sum>m)break;
		}
		if(sum<=m)
		{
			fs=md+1;
			mc=max(mc,md);
		}
		else
		{
			ls=md-1;
		}
	}
	printf("%lld",mc);
}