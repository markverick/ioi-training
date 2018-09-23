#include<bits/stdc++.h>
using namespace std;
long long n,Q;
long long c[6],d[6],v;
long long jum[100135][6];
long long dp(long long idx,long long C)
{
    if(jum[idx][C]>=0)
        return jum[idx][C];
    long long i;
    if(C>4)
    {
        if(idx==0)
            return 1;
        else
            return 0;
    }
    long long sum=0;
    for(i=0;idx-i*c[C]>=0&&i<=d[C];i++)
    {
        sum+=dp(idx-i*c[C],C+1);
    }
    return jum[idx][C]=sum;
}
int main()
{
    long long T,i,j,k;
    scanf("%lld",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        for(i=1;i<=4;i++)
            scanf("%lld",&c[i]);
        scanf("%lld",&Q);
        for(i=1;i<=Q;i++)
        {
            for(j=1;j<=4;j++)
                scanf("%lld",&d[j]);
            scanf("%lld",&v);
            printf("%lld\n",dp(v,1));
        }
    }
}
