#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long hsh[100135],tot[100135];
vector<long long> prm,v;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,a,sum=0;
	for(i=1;i<=100000;i++)
		tot[i]=i;
	for(i=2;i<=100000;i++)
	{
		if(hsh[i])continue;
		prm.emplace_back(i);
		for(j=i;j<=100000;j+=i)
			hsh[j]=1,tot[j]=tot[j]*(i-1)/i;
	}
	memset(hsh,0,sizeof hsh);
	scanf("%lld",&n);
	n++;
	for(j=1;j<=n;j++)
	{
		v.clear();
		scanf("%lld",&a);
		for(i=1;i*i<a;i++)
		{
			if(a%i==0)
			{
				if(hsh[i]==0)
					v.emplace_back(i);
				if(hsh[a/i]==0)
					v.emplace_back(a/i);
			}
		}
		if(i*i==a&&hsh[i]==0)
			v.emplace_back(i);
		for(i=0;i<v.size();i++)
		{
			sum+=tot[v[i]];
			hsh[v[i]]=1;
		}
	}
	printf("%lld\n",sum-1);
}