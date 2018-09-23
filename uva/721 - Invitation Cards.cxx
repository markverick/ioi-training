#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[1000135],adk[1000135];
int d[1000135],e[1000135];
priority_queue<pair<int,int> > pq;
int main()
{
    int T,i,j,k,n,m,a,b,c,w,u;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            d[i]=1000000000;
            e[i]=1000000000;
            adj[i].clear();
            adk[i].clear();
        }
        d[1]=0;
        e[1]=0;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a].emplace_back(b,c);
            adk[b].emplace_back(a,c);
        }
        pq.emplace(0,1);
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
        int sum=0;
        for(i=2;i<=n;i++)
        {
            sum+=d[i];
        }
        pq.emplace(0,1);
        while(!pq.empty())
        {
            tie(w,u)=pq.top();
            w=-w;
            pq.pop();
            for(i=0;i<adk[u].size();i++)
            {
                if(w+adk[u][i].Y<e[adk[u][i].X])
                {
                    e[adk[u][i].X]=w+adk[u][i].Y;
                    pq.emplace(-w-adk[u][i].Y,adk[u][i].X);
                }
            }
        }
        for(i=2;i<=n;i++)
        {
            sum+=e[i];
        }
        printf("%d\n",sum);
    }
}
