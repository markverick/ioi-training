#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int d[600][5];
vector<pair<int,int> > adj[600];
priority_queue<tuple<int,int,int> > pq;
// w,u,t;
int main()
{
    int i,j,k,a,b,c,T=1,w,u,t,n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            return 0;
        printf("Set #%d\n",T++);
        for(i=0;i<=505;i++)
            adj[i].clear();
        for(i=0;i<=505;i++)
        {
            d[i][0]=1000000000;
            d[i][1]=1000000000;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a].emplace_back(b,c);
            adj[b].emplace_back(a,c);
        }
        d[0][0]=0;
        pq.emplace(0,0,0);
        while(!pq.empty())
        {
            tie(w,u,t)=pq.top();
            w=-w;
            pq.pop();
            for(i=0;i<adj[u].size();i++)
            {
                if(d[adj[u][i].X][1-t]>w+adj[u][i].Y)
                {
                    d[adj[u][i].X][1-t]=w+adj[u][i].Y;
                    pq.emplace(-w-adj[u][i].Y,adj[u][i].X,1-t);
                }
            }
        }
        if(d[n-1][0]==1000000000)
            printf("?\n");
        else
            printf("%d\n",d[n-1][0]);
    }
}
