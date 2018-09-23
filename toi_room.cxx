#include<bits/stdc++.h>
using namespace std;
long long poww(long long b,long long p)
{
    if(p==0)
        return 1;
    long long temp=poww(b,p/2);
    temp*=temp;
    temp%=1000003;
    if(p%2)temp*=b;
    temp%=1000003;
    return temp;
}
int main()
{
    long long x,y,sum=1,div=1,i;
    scanf("%lld %lld",&x,&y);
    for(i=x;i>x-y;i--)
    {
        sum*=i;
        sum%=1000003;
    }
    for(i=y;i>=2;i--)
    {
        div*=i;
        div%=1000003;
    }
    printf("%lld",(sum*poww(div,(long long)1000001))%1000003);
}
