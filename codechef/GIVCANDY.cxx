#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,j,k,T,a,b,c,d,g,x;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        g=__gcd(c,d);
        x=a-b;
        if(x<0)x=-x;
        printf("%lld\n",min(x%g,(g-(x%g))%g));
    }
}
