#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int indeg[70];
int hsh[70][70];
int n,m,st;
vector<int> out;
vector<int> adj[70];
priority_queue<pair<int,int> > pq;
//deg,v
int main()
{
    int T,t,i,j,k,a,b,c,d,u,w;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&d);
        adj[d].emplace_back(a);
        adj[a].emplace_back(b);
        if(hsh[d][a]==0)
            indeg[a]++;
        hsh[d][a]=1;
        if(hsh[a][b]==0)
            indeg[b]++;
        hsh[a][b]=1;
    }
   // printf("=%d\n",indeg[2]);
    for(i=1;i<=n;i++)
    {
        pq.emplace(-indeg[i],i);
    }
    int fu=0;
    while(!pq.empty())
    {
        u=pq.top().Y;w=pq.top().X;
        //printf("%d %d\n",u,w);
        pq.pop();
        if(indeg[u]!=-w)
            continue;
        if(w<0)
        {
            fu=1;break;
        }
        out.emplace_back(u);
        for(i=0;i<adj[u].size();i++)
        {
            //printf("->%d\n",adj[u][i]);
            if(indeg[adj[u][i]]==0)
                continue;
            indeg[adj[u][i]]--;
            if(indeg[adj[u][i]]==0)
                pq.emplace(indeg[adj[u][i]],adj[u][i]);
        }
    }
    if(fu==1||out.size()!=n)
        printf("NO");
    else
    {
        printf("YES\n");
        for(i=0;i<out.size();i++)
        {
            printf("%d ",out[i]);
        }
    }
}
