#include<bits/stdc++.h>
using namespace std;
vector<long long> adj[100135];
vector<long long> adk[100135];
long long deg[100135];
long long hi=0;
long long jum[100135];
long long dp(long long idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(adk[idx].size()==0)
    {
        return 1;
    }
    long long sum=0,mc=0,i;
    for(i=0;i<adk[idx].size();i++)
    {
        mc=max(mc,dp(adk[idx][i])+1);
    }
    hi=max(hi,mc*deg[idx]);
    return mc;
}
int main()
{
    long long n,m,i,j,k,a,b;
    memset(jum,-1,sizeof jum);
    scanf("%I64d %I64d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%I64d %I64d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        if(a>b)
            adk[a].emplace_back(b);
        else
            adk[b].emplace_back(a);
    }
    for(i=1;i<=n;i++)
    {
        deg[i]=adj[i].size();
    }
    for(i=n;i>=1;i--)
    {
        dp(i);
//        printf("%I64d %I64d\n",i,hi);
    }
    printf("%I64d",hi);
}
