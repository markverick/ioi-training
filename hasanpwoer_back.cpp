#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long small[100135];
long long state[100135],shortest;
long long jum[100135][5];
long long memo[100135][5];
vector<pair<long long,long long> > adj[100135];
long long dp(long long idx,long long inc)
{
    if(jum[idx][inc]>=0)
        return jum[idx][inc];
    long long sum=0,mn=1000000000000000000,i,j;
    //prlong longf("%lld\n",idx);
    state[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i].X])
            continue;
            mn=1000000000000000000;
//        state[adj[idx][i].X]=1;
        if(inc==0)
        {
            mn=min(mn,dp(adj[idx][i].X,1)+adj[idx][i].Y);
            mn=min(mn,dp(adj[idx][i].X,0)+small[idx]);
//            mn=min(mn,dp(adj[idx][i].X,1)+small[idx]+small[adj[idx][i].X]);
        }
        else
        {
            mn=min(mn,dp(adj[idx][i].X,1)+adj[idx][i].Y);
            mn=min(mn,dp(adj[idx][i].X,1)+small[adj[idx][i].X]);
        }
        if(mn!=1000000000000000000)
            sum+=mn;
//        state[adj[idx][i].X]=0;
    }
    if(sum==0)
    {
        if(inc==0)
            return small[idx];
        else
            return 0;
//        prlong longf("->%lld\n",idx);
    }
    return jum[idx][inc]=sum;
}
long long mic(long long idx,long long inc,long long cost)
{
    if(memo[idx][inc]>=0)
        return memo[idx][inc];
    long long sum=0,i,j;
    //prlong longf("%lld\n",idx);
    state[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i].X])
            continue;
//        state[adj[idx][i].X]=1;
        if(inc==0)
        {
            sum+=mic(adj[idx][i].X,1,cost+adj[idx][i].Y);sum%1000000007;
            sum+=mic(adj[idx][i].X,0,cost+small[idx]);sum%1000000007;
//            sum+=mic(adj[idx][i].X,1,cost+small[idx]+small[adj[idx][i].X]);sum%1000000007;
        }
        else
        {
            sum+-mic(adj[idx][i].X,1,cost+adj[idx][i].Y);sum%1000000007;
            sum+=mic(adj[idx][i].X,1,cost+small[adj[idx][i].X]);sum%1000000007;
        }
//        state[adj[idx][i].X]=0;
    }
    if(sum==0)
    {
        if(cost==shortest)
            return 1;
        else
            return 0;
//        prlong longf("->%lld\n",idx);
    }
    return memo[idx][inc]=sum%1000000007;
}
int main()
{
    long long n,i,j,k,a,b,c;
    memset(jum,-1,sizeof jum);
    memset(memo,-1,sizeof memo);
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&small[i]);
    }
    for(i=1;i<n;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    state[1]=1;
    memset(state,0,sizeof state);
    long long mn=dp(1,1)+small[1];
    memset(state,0,sizeof state);
    mn=min(mn,dp(1,0));
    long long shortest=mn;
//    for(i=0;i<adj[1].size();i++)
//    {
//        mn=min(mn,dp(adj[1][i].X)+adj[1][i].Y);
//    }
    memset(state,0,sizeof state);
    long long sm=mic(1,0,0);
    memset(state,0,sizeof state);
    sm+=mic(1,1,small[1]);
    sm%=1000000007;    printf("%lld %lld",shortest,sm);
}

