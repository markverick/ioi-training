#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long x[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,T,t,a,b,n,cot=0,sum=0;
	scanf("%lld",&T);
	for(t=1;t<=T;t++)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&n,&x[1]);
        for(i=2;i<=n;i++)
            x[i]=(x[i-1]*a+b)%1000007;
        sort(&x[1],&x[n+1]);
        sum=x[1];cot=0;
        for(i=2;i<=n;i++)
        {
            cot+=x[i]*(i-1)-sum;
            sum+=x[i];
        }
        printf("Case %lld: %lld\n",t,cot);
    }
}
