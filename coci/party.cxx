#include<bits/stdc++.h>
using namespace std;
long long num[135],mul[135];
inline long long sum(long long x)
{
	return x*(x+1)/2;
}
int main()
{
	long long n,m,i,j,k,t,a,b,mc,x,sm=0;
	scanf("%lld %lld %lld",&n,&m,&t);
	for(i=1;i<=n;i++)
		scanf("%lld",&a),num[a]++;
	for(i=1;i<=m;i++)
		mul[i]=1;
	for(i=1;i<=t;i++)
	{
		mc=-1;
		for(j=1;j<=m;j++)
		{
			mul[j]++;
			k=sum(num[j]/mul[j])*(mul[j]-num[j]%mul[j])+sum(num[j]/mul[j]+1)*(num[j]%mul[j]);
			mul[j]--;
			b=sum(num[j]/mul[j])*(mul[j]-num[j]%mul[j])+sum(num[j]/mul[j]+1)*(num[j]%mul[j]);
			if(mc<b-k)
				mc=b-k;x=j;
		}
		mul[x]++;
	}
	for(j=1;j<=m;j++)
		sm+=sum(num[j]/mul[j])*(mul[j]-num[j]%mul[j])+sum(num[j]/mul[j]+1)*(num[j]%mul[j]);
	printf("%lld",sm);
}