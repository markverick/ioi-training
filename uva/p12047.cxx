#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int c[10135],d[10135],a[100135],b[100135],e[100135];
vector<pair<int,int> > adj[10135];
vector<pair<int,int> > adk[10135];
priority_queue<pair<int,int> >pq;
int main()
{
    int T,i,j,k,n,m,s,t,p,u,w;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d %d",&n,&m,&s,&t,&p);
        for(i=0;i<=10000;i++)
        {
            c[i]=100000000;d[i]=1000000000;
            adj[i].clear();adk[i].clear();
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a[i],&b[i],&e[i]);
            adj[a[i]].emplace_back(b[i],e[i]);
            adk[b[i]].emplace_back(a[i],e[i]);
        }
        pq.emplace(0,s);
        c[s]=0;
        while(!pq.empty())
        {
            u=pq.top().Y;
            w=-pq.top().X;
            pq.pop();
            for(i=0;i<adj[u].size();i++)
            {
                if(c[adj[u][i].X]>w+adj[u][i].Y)
                {
                    c[adj[u][i].X]=w+adj[u][i].Y;
                    pq.emplace(-w-adj[u][i].Y,adj[u][i].X);
                }
            }
        }
        while(!pq.empty())pq.pop();
        pq.emplace(0,t);
        d[t]=0;
        while(!pq.empty())
        {
            u=pq.top().Y;
            w=-pq.top().X;
            pq.pop();
            for(i=0;i<adk[u].size();i++)
            {
                if(d[adk[u][i].X]>w+adk[u][i].Y)
                {
                    d[adk[u][i].X]=w+adk[u][i].Y;
                    pq.emplace(-w-adk[u][i].Y,adk[u][i].X);
                }
            }
        }
        while(!pq.empty())pq.pop();
        int mc=-1;
        for(i=1;i<=m;i++)
        {
            //printf("%d %d %d %d\n",c[a[i]],d[b[i]],e[i],p);
            if(c[a[i]]+d[b[i]]+e[i]<=p)
                mc=max(mc,e[i] );
        }
        printf("%d\n",mc);
    }
}
