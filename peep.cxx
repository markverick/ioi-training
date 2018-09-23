#include<bits/stdc++.h>
using namespace std;
long long fac[500];
long long dp(long long idx,long long x)
{
    if(idx==0)
    {
        if(x==0)
            return 1;
        else
            return 0;
    }
    long long sum=0,i;
    for(i=idx-1;i>=0;i--)
    {
        sum+=dp(i,x-1)*fac[idx-i-1];
        sum%=1000007;
    }
    return sum;
}
int main()
{
    long long i,j,k,n,a,b,T;
    fac[0]=1;fac[1]=1;
    for(i=2;i<=333;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=1000007;
    }
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld %lld",&n,&a,&b);
        long long sum=0;
        printf("%lld\n",dp(n+1,a+b));
    }
}
