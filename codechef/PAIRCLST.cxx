#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair;
using namespace std;
vector<pair<int,int> > adj[100135];
priority_queue<pair<int,int> > pq;
int sp[100135],p[100135],d[100135],a[300135],b[300135],c[300135];
int main()
{
    int i,j,k,n,m,s,w,u;
    scanf("%d %d %d",&n,&m,&s);
    for(i=1;i<=n;i++)
        d[i]=1000000000;
    for(i=1;i<=s;i++)
    {
        scanf("%d",&sp[i]);
        d[sp[i]]=0;
        p[sp[i]]=sp[i];
        pq.emplace(0,sp[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        adj[a[i]].emplace_back(b[i],c[i]);
        adj[b[i]].emplace_back(a[i],c[i]);
    }
    while(!pq.empty())
    {
        tie(w,u)=pq.top();pq.pop();
        w=-w;
        for(i=0;i<adj[u].size();i++)
        {
            if(w+adj[u][i].Y<d[adj[u][i].X])
            {
                d[adj[u][i].X]=w+adj[u][i].Y;
                pq.emplace(-d[adj[u][i].X],adj[u][i].X);
                p[adj[u][i].X]=p[u];
            }
        }
    }
    int mn=1000000000;
    for(i=1;i<=m;i++)
    {
        if(p[a[i]]!=p[b[i]])
        {
            mn=min(mn,c[i]+d[a[i]]+d[b[i]]);
            mn=min(mn,c[i]+d[b[i]]+d[a[i]]);
        }
    }
    printf("%d",mn);
}
