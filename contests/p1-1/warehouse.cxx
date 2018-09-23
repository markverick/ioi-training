#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int go[8],n,m,k;
int perm[8],d[10135],isMart[10135];
int dis[8][8];
vector<pair<int,int> > adj[10135];
priority_queue<pair<int,int> > pq;
int dijk(int stf,int edf)
{
    if(dis[stf][edf]>=0)
        return dis[stf][edf];
    int u,w,i;
    int st=go[stf],ed=go[edf];
    for(i=1;i<=n;i++)
    {
        d[i]=1000000000;
    }
    d[st]=0;
    pq.emplace(0,st);
    while(!pq.empty())
    {
        w=-pq.top().X;
        u=pq.top().Y;
        pq.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(w+adj[u][i].Y<d[adj[u][i].X])
            {
                d[adj[u][i].X]=w+adj[u][i].Y;
                pq.emplace(-w-adj[u][i].Y,adj[u][i].X);
            }
        }
    }
    dis[stf][edf]=d[ed];
    dis[edf][stf]=d[ed];
    return d[ed];
}
int care(int st,int ed)
{
    int u,w,i;
    st=go[st];ed=go[ed];
    for(i=1;i<=n;i++)
    {
        d[i]=1000000000;
    }
    for(i=0;i<adj[st].size();i++)
    {
        if(isMart[adj[st][i].X])
            continue;
        d[adj[st][i].X]=adj[st][i].Y;
        pq.emplace(-adj[st][i].Y,adj[st][i].X);
    }
    while(!pq.empty())
    {
        w=-pq.top().X;
        u=pq.top().Y;
        pq.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(w+adj[u][i].Y<d[adj[u][i].X])
            {
                d[adj[u][i].X]=w+adj[u][i].Y;
                pq.emplace(-w-adj[u][i].Y,adj[u][i].X);
            }
        }
    }
    return d[ed];
}
int main()
{
    int i,j,a,b,c,mn=1000000000,sum=0;
    memset(dis,-1,sizeof dis);
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&go[i]);
        isMart[go[i]]=1;
        perm[i]=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    do
    {
        sum=0;
        for(i=2;i<=k;i++)
        {
            sum+=dijk(perm[i-1],perm[i]);
        }
        sum+=care(perm[k],perm[1]);
        mn=min(mn,sum);
    }
    while(next_permutation(&perm[1],&perm[k+1]));
    printf("%d",mn);
}
