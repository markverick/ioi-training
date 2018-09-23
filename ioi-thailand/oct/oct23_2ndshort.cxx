#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[10135],adk[10135];
int d[10135],e[10135],a[100135],b[100135],c[100135];
priority_queue<pair<int,int> > pq;
int main()
{
    int n,m,s,t,i,j,k,u,w;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        adj[a[i]].emplace_back(b[i],c[i]);
        adk[b[i]].emplace_back(a[i],c[i]);
    }
    for(i=0;i<=n;i++)
        d[i]=1000000000;
    d[s]=0;
    pq.emplace(0,s);
    while(!pq.empty())
    {
        tie(w,u)=pq.top();
        w=-w;
        pq.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(d[adj[u][i].X]>w+adj[u][i].Y)
            {
                d[adj[u][i].X]=w+adj[u][i].Y;
                pq.emplace(-w-adj[u][i].Y,adj[u][i].X);
            }
        }
    }
    int spath=d[t];
    for(i=0;i<=n;i++)
    {
        e[i]=1000000000;
    }
    e[t]=0;
        pq.emplace(0,t);
    while(!pq.empty())
    {
        tie(w,u)=pq.top();
        w=-w;
        pq.pop();
        for(i=0;i<adk[u].size();i++)
        {
            if(e[adk[u][i].X]>w+adk[u][i].Y)
            {
                e[adk[u][i].X]=w+adk[u][i].Y;
                pq.emplace(-w-adk[u][i].Y,adk[u][i].X);
            }
        }
    }
    int mn=1000000000;
    for(i=1;i<=m;i++)
    {
        if(d[a[i]]+e[b[i]]+c[i]>spath)
        {
            mn=min(mn,d[a[i]]+e[b[i]]+c[i]);
        }
    }
    printf("%d",mn);
}
