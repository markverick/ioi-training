#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,p,fs,md,ls,mn,sm=0;
	scanf("%lld %lld",&n,&p);
	for(i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	fs=0;ls=2000000000;mn=ls;
	while(fs<=ls)
	{
		md=(fs+ls)/2;
		for(i=1;i<=n;i++)
		{
			sm+=md/a[i];
		}
		if(sm>=p)
		{
			mn=min(mn,md);
			ls=md-1;
		}
		else
			fs=md+1;
	}
	printf("%lld",mn);
}