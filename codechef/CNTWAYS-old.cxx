#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
long long fac[1000135];
inline long long Pow(long long b,long long p)
{
    if(p==0)
        return 1;
    long long tmp=Pow(b,p/2);
    tmp*=tmp;tmp%=M;
    if(p%2)
        tmp*=b;
    return tmp%M;
}
inline long long ncr(long long n,long long r)
{
    return (fac[n]*Pow((fac[r]*fac[n-r])%M,M-2))%M;
}
int main()
{
    long long i,j,k,r,c,a,b,T,sum;
    fac[0]=1;
    for(i=1;i<=1000000;i++)
        fac[i]=fac[i-1]*i,fac[i]%=M;
    scanf("%lld",&T);
    while(T--)
    {
        sum=0;
        scanf("%lld %lld %lld %lld",&r,&c,&a,&b);
        for(i=0;i<=r-a;i++)
        {
            sum+=(ncr(i+b-1,i)*ncr(r-i+c-b,c-b))%M;
            sum%=M;
//            printf("%lld\n",sum);
        }
        printf("%lld\n",sum);
    }
}
