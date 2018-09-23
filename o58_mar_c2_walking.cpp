#include<bits/stdc++.h>
using namespace std;
int n,req,s[6135];
vector<int> adj[6135];
int jum[6006],mn=1000000000;
int a[6005],b[6005];
inline void dp(int idx,int p,int cost,int time)
{
    int i;
    if(cost<=0)
    {
        mn=min(mn,time);
        return;
    }
//    printf("%d %d\n",idx,cost);
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==p)
            continue;
        dp(adj[idx][i],idx,cost-s[adj[idx][i]],time+1);
    }
    return;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&req);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        a[i]++;b[i]++;
        adj[a[i]].emplace_back(b[i]);
        adj[b[i]].emplace_back(a[i]);
    }
    for(i=1;i<n;i++)
    {
        dp(b[i],a[i],req-s[a[i]]-s[b[i]],1);
        dp(a[i],b[i],req-s[a[i]]-s[b[i]],1);
    }

    if(mn==1000000000)
        printf("%d",-1);
    else
        printf("%d",mn);
}
