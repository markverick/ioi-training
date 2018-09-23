#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[5135],b[5135];
vector<int> adj[5135];
pair<int,int> v[5135];
pair<int,int> dp[5135];
int main()
{
    int i,j,k,n,m;
    scanf("%d %d",&n,&m);
    for(i=0;i<=m;i++)
    {
        dp[i]=make_pair(-1000000000,-1000000000);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&v[i].X,&v[i].Y);
    }
    sort(&v[1],&v[m+1]);
    for(i=1;i<=m;i++)
    {
        tie(a[i],b[i])=v[i];
        if(a[i]<=1)
        {
            dp[i]=make_pair(1,b[i]);
            adj[0].emplace_back(i);
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=i+1;j<=m;j++)
        {
            if(a[j]>a[i]&&a[j]<=b[i])
                adj[i].emplace_back(j);
        }
    }
    for(i=1;i<=m;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            if(dp[i].X+1>dp[adj[i][j]].X)
            {
                dp[adj[i][j]].X=dp[i].X+1;
                dp[adj[i][j]].Y=b[adj[i][j]];
            }
            else if(dp[i].X+1==dp[adj[i][j]].X)
            {
                dp[adj[i][j]].X=dp[i].X+1;
                dp[adj[i][j]].Y=max(dp[adj[i][j]].Y,b[adj[i][j]]);
            }
        }
    }
    int mc=-1000000000,dmc=-1000000000;
    for(i=1;i<=m;i++)
    {
        if(mc<dp[i].X)
        {
            mc=dp[i].X;
            dmc=dp[i].Y;
        }
        else if(mc==dp[i].X)
        {
            dmc=max(dmc,dp[i].Y);
        }
    }
    printf("%d %d",mc,dmc);
}
