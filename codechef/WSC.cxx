#include<bits/stdc++.h>
using namespace std;
int n,n;
vector<int> adj[12];
int mat[12][12];
int dp(int bit,int boat)
{
    if(__builtin_popcount(bit)==n)
    {
        return 1;
    }
    int mc=0,i,hsh[n],j,fu;
    memset(hsh,0,sizeof hsh);
    for(i=0;i<n;i++)
    {
        fu=0;
        if(boat^(((1<<i)|bit)!=bit))
        {
            memset(hsh,0,sizeof hsh);
            for(j=0;j<n;j++)
            {
                if(i==j)continue;
                for(j=0;j<adj[i].size();j++)
                {
                    hsh[adj[i][j]]=1;
                }
            }
            for(j=0;j<n;j++)
            {
                if(i==j)continue;
                if(hsh[j])
                    fu=1;
            }
        }
        if(fu==0)
        {
            if(boat==0)
                mc=max(mc,dp(bit|(1<<i),1-boat));
        }
    }
    for(i=0;i<n;i++)
    {
        if(boat^(((1<<i)|bit)!=bit))
        {
            for(j=0;j<adj[i].size();j++)
                hsh[adj[i][j]]=1;
        }
    }
}
int main()
{
    int i,j,k,T,a,b;
    sacnf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
            mat[a][b]=1;
            mat[b][a]=1;
        }
        printf("%d\n",dp(0,0));
    }
}
