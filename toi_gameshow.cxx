#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int r,c,n;
int x[12],y[12];
vector<pair<int,int> > adj[12];
int jum[12][5005];
int dp(int idx,int bit)
{
    if(__builtin_popcount(bit)==n)
    {
        return 0;
    }
    if(jum[idx][bit]>=0)
        return jum[idx][bit];
    int mc=0,i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(bit!=(bit|(1<<(adj[idx][i].X-1) )) )
        {
            mc=max(mc,adj[idx][i].Y+dp(adj[idx][i].X,bit|(1<<(adj[idx][i].X-1))));
        }
    }
    return jum[idx][bit]=mc;
}
int main()
{
    int i,j;
    scanf("%d %d %d",&r,&c,&n);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j)
                continue;
            adj[i].emplace_back(j,abs(x[i]-x[j])+abs(y[i]-y[j]) );
        }
    }
    int mc=0;
    for(i=1;i<=n;i++)
    {
        mc=max(mc,dp(i,1<<(i-1)) );
    }
    printf("%d",mc);
}
