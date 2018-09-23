#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
using namespace std;
vector<long long> adj[23];
long long mat[23][23],n;
long long jum[21][263144];
long long fst;
long long dp(long long idx,long long bit)
{
    if(jum[idx][bit]>=0)
        return jum[idx][bit];
    if(__builtin_popcount(bit)==n-2)
    {
        return mat[fst][n]+mat[idx][n]+mat[1][idx];
    }
    long long mn=1000000000000000000,i;
    for(i=2;i<n;i++)
    {
        if((bit|(1<<(i-2)))==bit)
            continue;
        mn=min(mn,dp(i,bit|(1<<(i-2)))+2*mat[i][idx]);
    }
    return jum[idx][bit]=mn;
}
int main()
{
    long long m,i,j,k,a,b,c,T=0;
    while(scanf("%lld %lld",&n,&m)!=EOF)
    {
        T++;
        memset(jum,0,sizeof jum);
        for(i=1;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                mat[i][j]=1000000000000000000;
        for(i=1;i<=n;i++)
            mat[i][i]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            a++;b++;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
            mat[a][b]=c;
            mat[b][a]=c;
        }
        for(k=1;k<=n;k++)
            for(i=1;i<=n;i++)
                for(j=1;j<=n;j++)
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
        long long mn=1000000000000000000;
        for(i=2;i<n;i++)
        {
            memset(jum,-1,sizeof jum);
            fst=i;
            mn=min(mn,dp(i,1<<(i-2))+mat[1][i]);
        }
        printf("Case %lld: %lld\n",T,mn);
    }
}
