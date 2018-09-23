#include<bits/stdc++.h>
using namespace std;
long long fac[10135];
long long Pow(long long b,long long p)
{
    if(p==0)
        return 1;
    long long temp=Pow(b,p/2);
    temp*=temp;
    temp%=1000000007;
    if(p%2)temp*=b;
    temp%=1000000007;
    return temp;
}
int main()
{
    long long i,j,k,T,n,a,b;
    scanf("%lld",&T);
    fac[0]=1;
    for(i=1;i<=10005;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=1000000007;
    }
    while(T--)
    {
        scanf("%lld %lld",&n,&k);
        if(n<k)
        {
            printf("-1\n");
        }
        else
        {
            a=fac[n-1];
            b=fac[k-1]*fac[n-k];
            b%=1000000007;
            printf("%lld\n",(a*Pow(b,1000000005))%1000000007);
        }
    }
}
