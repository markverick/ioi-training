#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[111];
int d[111],e[111],a[10135],b[10135],c[10135];
priority_queue<pair<int,int> > pq;
int main()
{
//    freopen("out.txt","w",stdout);
    int T,i,j,k,n,m,w,u,mn,t=0,Q,x,y;;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        t++;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
            a[i]++;b[i]++;
            adj[a[i]].emplace_back(b[i],c[i]);
            adj[b[i]].emplace_back(a[i],c[i]);
        }
        printf("Set #%d\n",t);
        scanf("%d",&Q);
        while(Q--)
        {
            scanf("%d %d",&x,&y);
            x++;y++;
            for(i=1;i<=n;i++)
            {
                d[i]=1000000000;
                e[i]=1000000000;
            }
            d[x]=0;e[y]=0;
            pq.emplace(0,x);
            while(!pq.empty())
            {
                tie(w,u)=pq.top();
                w=-w;
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
            pq.emplace(0,y);
            while(!pq.empty())
            {
                tie(w,u)=pq.top();
                w=-w;
                pq.pop();
                for(i=0;i<adj[u].size();i++)
                {
                    if(w+adj[u][i].Y<e[adj[u][i].X])
                    {
                        e[adj[u][i].X]=w+adj[u][i].Y;
                        pq.emplace(-w-adj[u][i].Y,adj[u][i].X);
                    }
                }
            }
            mn=1000000000;
            for(i=1;i<=m;i++)
            {
                if(d[a[i]]+c[i]+e[b[i]]<mn&&d[a[i]]+c[i]+e[b[i]]!=d[y])
                {
                    mn=d[a[i]]+c[i]+e[b[i]];
                }
            }
            for(i=1;i<=m;i++)
            {
                if(d[b[i]]+c[i]+e[a[i]]<mn&&d[b[i]]+c[i]+e[a[i]]!=d[y])
                {
                    mn=d[b[i]]+c[i]+e[a[i]];
                }
            }
            if(mn==1000000000)
                printf("?\n");
            else
                printf("%d\n",mn);
        }
    }
}
