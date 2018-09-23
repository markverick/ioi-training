#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long n,i,a,b,c;
    scanf("%lld",&n);
    scanf("%lld",&b);
    for(i=2;i<=n;i++)
    {
        scanf("%lld",&a);
        b=__gcd(a,b);
    }
    long long cot=0;
    for(i=1;i<=sqrt(b);i++)
    {
        if(b%i==0)
            cot++;
        if(b/i!=i&&b%(b/i)==0)
            cot++;
    }
    printf("%lld",cot);
}
