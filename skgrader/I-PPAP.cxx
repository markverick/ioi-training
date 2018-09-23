#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long dp(long long n,long long prod,long long inv)
{
	// prlong longf("%lld %lld %lld\n",n,prod,inv);
	if(prod==1)return inv;
	if(n==prod/3+1)
	{
		return inv;
	}
	else if(n<=prod/3)
		return dp(n,prod/3,inv);
	else if(n>=(prod/3)*2+2)
		return dp(n-(prod/3)*2-1,prod/3,inv);
	else
		return dp(n-prod/3-1,prod/3,inv^1);

}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k,T,prod=1;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		// n--;
		while(prod<n)
			prod=prod*3+1;
		if(dp(n,prod,0)==0)
			printf("P\n");
		else
			printf("A\n");
	}
}