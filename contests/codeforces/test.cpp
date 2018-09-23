#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
map<long long,long long> m;
long long power(long long a,long long b)
{
	if(b==0)return 1;
	if(b==1)return a;
	long long c=power(a,b/2);
	if(b%2)return (((c*c)%MOD)*a)%MOD;
	else return (c*c)%MOD;
}
int main()
{
	long long  a,b,c,sum=1,num=1;
	vector<long long> v;
	cin>>a;
	for(b=0;b<a;b++)
	{
		cin>>c;
		if(m[c]==0)v.push_back(c);
		m[c]++;
		sum*=c;
		sum%=1000000007;
	}
	for(b=0;b<v.size();b++)
	{
		num*=m[v[b]]+1;
	}
	if(num%2)sum=(power(sum,num/2)*(long long)sqrt(sum))%1000000007;
	else sum=power(sum,num/2);
	cout<<sum;
}
