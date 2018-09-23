#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m,ar[200135];
priority_queue<pair<int,int> > pq;
vector<pair<int,int> > adj[200135];
int d[200135],h[200135];
int main()
{
    int i,j,k,a,b,c,u,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&d[i]);
        pq.emplace(d[i],i);
        h[i]=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    while(!pq.empty())
    {
        tie(w,u)=pq.top();
        pq.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(w-adj[u][i].Y>d[adj[u][i].X])
            {
                d[adj[u][i].X]=w-adj[u][i].Y;
                h[adj[u][i].X]=h[u];
                pq.emplace(d[adj[u][i].X],adj[u][i].X);
            }
            else if(w-adj[u][i].Y==d[adj[u][i].X])
            {
                h[adj[u][i].X]=min(h[adj[u][i].X],h[u]);
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        if(d[i]>0)
            printf("%d %d\n",h[i],d[i]);
        else
            printf("0 0\n");
    }
}
