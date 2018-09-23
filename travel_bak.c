#include<bits/stdc++.h>
using namespace std;
vector<int> adj[30135];
priority_queue<pair<int,int> > pq;
int d[30135],e[30135];
int main()
{
    int n,m,i,j,k,w,u,a,b,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n-1;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&e[i]);
    }
    for(i=2;i<=m;i++)
    {
        for(j=0;j<=30005;j++)
        {
            d[j]=100000000;
        }
        d[e[i-1]]=0;
        pq.emplace(0,e[i-1]);
        while(!pq.empty())
        {
            tie(w,u)=pq.top();
            w=-w;
            pq.pop();
            for(j=0;j<adj[u].size();j++)
            {
                if(d[adj[u][j]]>w+1)
                {
                    d[adj[u][j]]=w+1;
                    pq.emplace(-w-1,adj[u][j]);
                }
            }
        }
        sum+=d[e[i]];
    }
    printf("%d",sum);
}
