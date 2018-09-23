#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int n,m,h[100135],state[100135],Max,late=0,p[100135],hsh[100135],sum=0,good[100135];
vector<pair<int,int> > adj[100135];
void dp(int idx)
{
    int i,fu=0;
    if(hsh[idx]==1)
        good[idx]=1;
    if(adj[idx].empty())
    {
        return;
    }
    for(i=0;i<adj[idx].size();i++)
    {
        h[adj[idx][i].X]=h[idx]+adj[idx][i].Y;
        dp(adj[idx][i].X);
        if(good[adj[idx][i].X]==1)
            good[idx]=1;
    }
    return;
}
void dfs(int idx)
{
    if(adj[idx].empty())
    {
        return;
    }
    for(int i=0;i<adj[idx].size();i++)
    {
        if(good[adj[idx][i].X]==0)
            continue;
        dfs(adj[idx][i].X);
        sum+=adj[idx][i].Y;
    }
}
int main()
{
    int i,j,k,x,a,b,c;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        sum=0;
        memset(h,0,sizeof h);
        memset(hsh,0,sizeof hsh);
        memset(p,0,sizeof p);
        memset(good,0,sizeof good);
        for(i=1;i<=n;i++)
            adj[i].clear();
        for(i=1;i<n;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a].emplace_back(b,c);
            p[b]=a;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d",&a);
            hsh[a]=1;
        }
        h[1]=0;
        dp(1);
        dfs(1);
//        for(i=1;i<=n;i++)
//        {
//            printf("%d %d\n",h[i],good[i]);
//        }
        Max=0;
        for(i=1;i<=n;i++)
        {
            if(good[i])
            {
                Max=max(Max,h[i]);
            }
        }
        printf("%d\n",sum-Max);
    }
}
