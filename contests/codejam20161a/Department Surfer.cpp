#include<bits/stdc++.h>
using namespace std;
long long fac[1000135];
long long poww(long long b,long long p)
{
    if(p==0)
        return 1;
    long long temp=poww(b,p/2);
    temp*=temp;
    temp%=1000000007;
    if(p%2)temp*=b;
    temp%=1000000007;
    return temp;
}
long long ncr(long long n,long long r)
{
    long long sm=fac[n];
    long long di=fac[r]*fac[n-r];
    di%=1000000007;
    di=poww(di,1000000005);
//    printf("%lld %lld %lld\n",n,r,(sm*di)%1000000007);
    return (sm*di)%1000000007;
}
int main()
{
    long long T,n,i,j,k,x,y,a,b,c,d,out,p,q;
    fac[0]=1;
    fac[1]=1;
    for(i=2;i<=1000002;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=1000000007;
    }
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        c--;d--;
        x=ncr(a+b,a);
        x%=1000000007;
        y=0;
        for(i=0;i<=c;i++)
        {
            y+=fac[c+d+1-i]*poww(fac[c+1-i],1000000005);
            y%=1000000007;
        }
        y*=poww(fac[d],1000000005);
        out=x-y;
//        printf("%lld %lld\n",x,y);
        while(out<0)
            out+=1000000007;
        printf("%lld\n",out);
    }
}
