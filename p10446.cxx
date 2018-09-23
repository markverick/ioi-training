#include<bits/stdc++.h>
using namespace std;
unsigned long long jum[64][64];
unsigned long long dp(long long n, long long bk)
{
    long long i;
    unsigned long long sum=0;
    if(n<=0) return 1;
    if(n==1) return 1;
    if(jum[n][bk]>0)
        return jum[n][bk];
    for(i=1;i<=bk;i++)
    sum+=dp(n-i,bk);
    return jum[n][bk]=sum+1;
}
int main()
{
    long long a,b,T=0;
   // memset(jum,-1,sizeof jum);
    while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        if(a>60)
            return 0;
        T++;
        printf("Case %lld: %llu\n",T,dp(a,b));
    }
}
