#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
long long fac[2000135];
long long Pow(long long b,long long p)
{
    if(p==0)
        return 1;
    long long tmp=Pow(b,p/2);
    tmp*=tmp;tmp%=M;
    if(p%2)
        tmp*=b;
    return tmp%M;
}
int main()
{
    long long i,j,k,T,n,m,a,b,sum=0;
    scanf("%lld",&T);
    fac[0]=1;
    for(i=1;i<=2000005;i++)
        fac[i]=fac[i-1]*i,fac[i]%=M;
    while(T--)
    {
        sum=0;
        scanf("%lld %lld",&n,&m);
        a=fac[n+m+1];
        b=Pow((fac[n-1]*fac[m+2])%M,M-2);
        sum=((a*b)%M)*2-n;
        sum%=M;
        if(sum<0)sum+=M;
        printf("%lld\n",sum);
    }
}
