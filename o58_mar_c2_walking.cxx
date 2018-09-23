#include<bits/stdc++.h>
using namespace std;
int n,req,s[6135];
vector<int> adj[6135];
int dp(int idx,int p,int cost)
{
    if(cost<=1)
        return s[idx];
    int mc=0,i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==p)
            continue;
        mc=max(mc,dp(adj[idx][i],idx,cost-1));
    }
    return mc+s[idx];
}
int main()
{
    int i,j,k,a,b;
    scanf("%d %d",&n,&req);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
    }
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        a++;b++;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    int fst=0,mid,lst=n,mc=0,mn=1000000000;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        mc=0;
        for(i=1;i<=n;i++)
        {
            mc=max(mc,dp(i,0,mid+1));
        }
        if(mc>=req)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    printf("%d",mn);
}
