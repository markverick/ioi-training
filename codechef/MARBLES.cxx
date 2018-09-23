#include<bits/stdc++.h>
using namespace std;
long long fac[1000005];
int main()
{
    long long T,i,j,k,n,m,a,b,d,td;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld",&n,&m);
        a=n-1;b=m-1;
        if(a-b<b)
            b=a-b;
        td=1;
        for(i=a;i>a-b;i--)
        {
            d=__gcd(td,a-i+1);
            td/=d;
            td*=(i/((a-i+1)/d));
        }
        printf("%lld\n",td);
    }
}
