#include<bits/stdc++.h>
using namespace std;

long long kp[5200];
long long km[5200];
long long poww(long long b,long long p)
{
    if(p==0)
        return 1;
    long long temp=poww(b,p/2);
    temp*=temp;
    temp%=2553;
    if(p%2)temp*=b;
    temp%=2553;
    return temp;
}
int main()
{
    long long n,m,i,j;
    scanf("%lld %lld",&n,&m);
    kp[1]=1;km[1]=1;
    for(i=1;i<=2553;i++)
    {
        for(j=2553;j>=0;j--)
        {
            kp[(j*i)%2553]+=km[j];
            kp[(j*i)%2553]%=2553;
        }
        for(i=0;i<=2553;i++)
        {
            km[i]=kp[i];
        }
    }
    long long sum=0;
    for(i=m;i<=n;i+=m)
    {
        sum+=km[poww((long long)1001,n-i)];
    }
    printf("%lld",sum);
}
