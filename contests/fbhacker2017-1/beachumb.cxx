#include<bits/stdc++.h>
#define MI 1000000000
#define M 1000000007
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[2135],fac[2135],jum[4135];
long long Pow(long long b,long long p)
{
	if(p==0)return 1;
	long long x=Pow(b,p/2);
	x*=x;x%=M;
	if(p%2)
		x*=b,x%=M;
	return x;
}
long long ncr(long long a,long long b)
{
	if(a<0)
		return 0;
	long long ret=1,i;
	for(i=a;i>a-b;i--)
		ret*=i,ret%=M;
	for(i=1;i<=b;i++)
		ret*=Pow(i,M-2),ret%=M;
	// printf("%lld %lld = %lld\n",a,b,ret);
	return ret;
}
int main()
{
	freopen("out3.txt","w",stdout);
	freopen("in3.txt","r",stdin);
	long long T,t,i,j,k,sm=0,n,m,prod=0,I;
	fac[0]=1;
	for(i=1;i<=2100;i++)
		fac[i]=fac[i-1]*i,fac[i]%=M;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
	{
		sm=0;prod=0;
		memset(jum,-1,sizeof jum);
		scanf("%lld %lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sm+=a[i];
		}
		if(n==1)
		{
			printf("Case #%lld: %lld\n",t,m);
			continue;
		}
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)continue;
				k=m+a[i]+a[j]-sm*2-1;
				if(k<0)continue;
				if(jum[a[i]+a[j]]>=0)
				{
					prod+=jum[a[i]+a[j]];
					prod%=M;
					continue;
				}
				// printf("%lld %lld\n",k+n,n);
				I=(ncr(k+n,n)*fac[n-2])%M;
				jum[a[i]+a[j]]=I;
				prod+=I;
				prod%=M;
			}
		}
		printf("Case #%lld: %lld\n",t,prod);
	}
}