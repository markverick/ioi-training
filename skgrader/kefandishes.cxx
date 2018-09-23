#include<bits/stdc++.h>
using namespace std;
int n,m,r;
long long w[20];
long long bonus[20][20];
long long jum[20][270000];
long long dp(int idx,int bit)
{
    long long mc=0;
    int i,bi,bn=__builtin_popcount(bit);
    if(jum[idx][bit]>=0)
        return jum[idx][bit];
    if(bn==m/*||bit==(1<<n)-1*/ )
    {
        return 0;
    }
    for(i=1;i<=n;i++)
    {
        bi=(1<<(i-1) );
        if((bit|bi)==bit)
            continue;
        if(bn+1<=m)
            mc=max(mc,dp(i,(bit|bi))+w[i]+bonus[idx][i]);
    }
    return jum[idx][bit]=mc;
}
int main()
{
    int i,j,k,a,b;
    long long c;
    scanf("%d %d %d",&n,&m,&r);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&w[i]);
    }
    for(i=1;i<=r;i++)
    {
        scanf("%d %d %I64d",&a,&b,&c);
        bonus[a][b]=c;
    }
    printf("%I64d",dp(0,0));
}
