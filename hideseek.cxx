#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> adj[200135];
int d[200135];
priority_queue<pair<int,int> > pq;
// w v
int n,m;
int main()
{
    int i,j,k,a,b,w,u;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(i=1;i<=n;i++)
    {
        d[i]=1000000000;
    }
    pq.emplace(0,1);
    d[1]=0;
    while(!pq.empty())
    {
        w=-pq.top().X;
        u=pq.top().Y;
        pq.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(d[adj[u][i]]>w+1)
            {
                d[adj[u][i]]=w+1;
                pq.emplace(-(w+1),adj[u][i]);
            }
        }
    }
    int mc=0,cot=0;
    int x;
    for(i=1;i<=n;i++)
    {
        if(d[i]>mc)
        {
            mc=d[i];
            x=i;
        }
    }
    for(i=1;i<=n;i++)
    {
        if(d[i]==mc)
            cot++;
    }
    printf("%d %d %d",x,d[x],cot);
}
