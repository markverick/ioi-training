#include<bits/stdc++.h>
using namespace std;
long long n;
char mat[20][20],buster[20];
long long jum[66000];
long long dp(long long bit)
{
    if(jum[bit]>=0)
        return jum[bit];
    long long i,j;
    if(__builtin_popcount(bit)==n)
    {
        return 1;
    }
    long long sum=0;
    long long hsh[20];
    long long ha[20];
    memset(hsh,0,sizeof hsh);
    memset(ha,0,sizeof ha);
    for(i=1;i<=n;i++)
    {
        if((bit|(1<<(i-1)))==bit)
        {
            hsh[i]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(!hsh[i])
            continue;
        for(j=1;j<=n;j++)
        {
            if(mat[i][j]==1)
            {
                ha[j]=1;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if((bit|(1<<(i-1)))!=bit)
        {
            if(ha[i]||buster[i])
                sum+=dp(bit|(1<<(i-1)));
        }
    }
    return jum[bit]=sum;
}
int main()
{
    long long i,j,k,T,t=0;
    scanf("%lld",&T);
    while(T--)
    {
        memset(jum,-1,sizeof jum);
        memset(mat,0,sizeof mat);
        t++;
        scanf("%lld",&n);
        scanf("%s",buster+1);
        for(i=1;i<=n;i++)
        {
            scanf("%s",mat[i]+1);
            for(j=1;j<=n;j++)
                mat[i][j]-='0';
        }
        for(i=1;i<=n;i++)
            buster[i]-='0';
        printf("Case %lld: %lld\n",t,dp(0));
    }
}
