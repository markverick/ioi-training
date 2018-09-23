#include<bits/stdc++.h>
using namespace std;
long long qs[1000000];
int main()
{
    long long T,a,b,i,j,k,sum=0;
    scanf("%lld",&T);
    for(i=1;i<=500000;i++)
    {
        qs[i]=qs[i-1]+i;
    }
    while(T--)
    {
        scanf("%lld %lld",&a,&b);
        sum=0;
        for(i=2;i<=33000;i++)
        {
            if(b-qs[i-1]>0)
                sum+=(b-qs[i-1])/i;
            if(a-1-qs[i-1]>0)
                sum-=(a-1-qs[i-1])/i;
        }
        printf("%lld\n",sum);
    }
}
