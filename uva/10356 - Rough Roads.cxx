#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[555];
priority_queue<tuple<int,int,int> > pq;
int d[555][5];
int main()
{
//    freopen("out.txt","w",stdout);
    int n,m,i,j,k,a,b,c,w,u,cyc,T=0;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        T++;
        for(i=0;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            a++;b++;
            adj[a].emplace_back(b,c);
            adj[b].emplace_back(a,c);
        }
        pq.emplace(0,1,0);
        for(i=1;i<=n;i++)
        {
            d[i][0]=1000000000;
            d[i][1]=1000000000;
        }
        d[1][0]=0;
        while(!pq.empty())
        {
            tie(w,u,cyc)=pq.top();
            w=-w;
            pq.pop();
            for(i=0;i<adj[u].size();i++)
            {
                if(w+adj[u][i].Y<d[adj[u][i].X][1-cyc])
                {
                    d[adj[u][i].X][1-cyc]=w+adj[u][i].Y;
                    pq.emplace(-w-adj[u][i].Y,adj[u][i].X,1-cyc);
                }
            }
        }
        printf("Set #%d\n",T);
        if(d[n][0]==1000000000)
            printf("?\n");
        else
            printf("%d\n",d[n][0]);
    }
}
