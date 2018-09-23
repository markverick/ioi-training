#include<bits/stdc++.h>
#define MI 1000000000ll
#define M 1000000007ll
#define EPS 0.0000000001
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<double> v;
vector<long long> x;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,zero=0,sm=0,sum=0,a,b,c,prod=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld %lld %lld",&a,&b,&c);
		if(b==0)
			zero++;
		else
			v.emplace_back((double)a/b);
	}
	sort(v.begin(),v.end());
	if(zero)
		x.emplace_back(zero);
	j=1;
	for(i=1;i<v.size();i++)
	{
		if(abs(v[i]-v[i-1])<=EPS)
			j++;
		else
		{
			x.emplace_back(j);
			j=1;
		}
	}
	x.emplace_back(j);
	for(i=0;i<x.size();i++)
	{
		sum+=(prod*x[i])%M;sum%=M;
		prod+=(sm*x[i])%M;prod%=M;
		sm+=x[i];sm%=M;
	}
	printf("%lld\n",sum);
}