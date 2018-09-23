#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[600],adk[600],adi[600];
int d[600],e[600],a[10135],b[10135],c[10135],hsh[10135];
priority_queue<pair<int,int> > pq;
int main()
{
    int n,m,s,t,i,j,k,u,w;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            return 0;
        scanf("%d %d",&s,&t);
        for(i=0;i<=531;i++)
        {
            adj[i].clear();adk[i].clear();adi[i].clear();
        }
        memset(hsh,0,sizeof hsh);
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
            if(d[a[i]]+e[b[i]]+c[i]==spath)
            {
                hsh[i]=1;
            }
        }
        for(i=1;i<=m;i++)
        {
            if(hsh[i])
                continue;
            adi[a[i]].emplace_back(b[i],c[i]);
        }
        for(i=0;i<=n;i++)
        {
            d[i]=1000000000;
        }
        d[s]=0;
        pq.emplace(0,s);
        while(!pq.empty())
        {
            tie(w,u)=pq.top();
            pq.pop();
            w=-w;
            for(i=0;i<adi[u].size();i++)
            {
                if(d[adi[u][i].X]>w+adi[u][i].Y)
                {
                    d[adi[u][i].X]=w+adi[u][i].Y;
                    pq.emplace(-w-adi[u][i].Y,adi[u][i].X);
                }
            }
        }
        if(d[t]==1000000000)
            printf("-1\n");
        else
            printf("%d\n",d[t]);
    }
}
