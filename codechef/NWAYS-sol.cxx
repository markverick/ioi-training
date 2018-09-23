#include<cstdio>
using namespace std;

typedef long long int big;

big mod = 1000000007;

big pow(big a,big b)
{
	if(b==0)
	 return 1;

	if(b==1)
	 return a;
	if(b==2)
	 return a*a %mod;
	if(b%2)
	 return a*pow(pow(a,(b-1)/2),2) %mod;
	else
	 return pow(pow(a,b/2),2);
}

big fact[2000002];

void init()
{
	fact[0]=fact[1]   =1;

	for(int i=2;i<2000002;i++)
	 fact[i] = fact[i-1]*i %mod;
}

main()
{
	init();

	int t;
	big N,k,ans;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%lld %lld",&N,&k);

		ans = fact[k+N+1];
		ans = (ans * pow(fact[N-1],mod-2)) %mod;
		ans = (ans * pow(fact[k+2],mod-2)) %mod;
		ans = (ans*2) %mod;

		ans = (ans - N + mod) %mod;
		printf("%lld\n",ans);
	}
}
