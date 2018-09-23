#include<bits/stdc++.h>
#define X first
#define Y second
#define EB emplace_back
using namespace std;
long long a[1135][1135],h[1135][1135],sum=0;
vector<pair<long long,long long> > v;
long long ch2(long long n)
{
	return n*(n-1)/2;
}
pair<long long,long long> back()
{
	return v[v.size()-1];
}
pair<long long,long long> bb()
{
	return v[v.size()-2];
}
void clr(long long n)
{
	while(v.size()>1)
	{
		sum+=ch2(n-back().Y+1)*(back().X-bb().X);
		v.pop_back();
	}
}
int main()
{
	long long r,c,i,j,k;
	scanf("%lld %lld",&r,&c);
	for(i=1;i<=r;i++)
		for(j=1;j<=c;j++)
			scanf("%lld",&a[i][j]);
	for(j=1;j<=c;j++)
	{
		h[1][j]=1;
		for(i=1;i<=r;i++)
		{
			if(a[i][j]==a[i-1][j])
				h[i][j]=h[i-1][j]+1;
			else
				h[i][j]=1;
		}
	}
	for(i=1;i<=r;i++)
	{
		v.clear();
		v.EB(0,1);
		v.EB(h[i][1],1);
		for(j=2;j<=c;j++)
		{
			if(a[i][j]!=a[i][j-1])
				clr(j);
			k=j;
			while(v.size()>1&&h[i][j]<back().X)
			{
				sum+=ch2(j-back().Y+1)*(back().X-max(bb().X,h[i][j]));
				k=back().Y;
				v.pop_back();
			}
			if(back().X!=h[i][j])
				v.EB(h[i][j],k);
		}
		clr(c+1);
	}
	printf("%lld",sum);
}