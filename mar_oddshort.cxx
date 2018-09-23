#include<bits/stdc++.h>
#define X first
#define Y second
#define EB emplace_back
using namespace std;
vector<pair<int,int> > adj[10135];
int d[10135][5];
priority_queue<tuple<int,int,int> > pq;
int main()
{
    int n,m,s,t,i,j,k,a,b,c,w,u;
    scanf("%d %d %d %d",&n,&m,&s,&t);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].EB(b,c);
        adj[b].EB(a,c);
    }
    for(i=0;i<=10005;i++)
    {
        for(j=0;j<=1;j++)
            d[i][j]=1000000000;
    }
    pq.emplace(0,0,s);
    d[s][0]=0;
    while(!pq.empty())
    {
        tie(w,c,u)=pq.top();w=-w;
        pq.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(w+adj[u][i].Y<d[adj[u][i].X][1-c])
            {
                d[adj[u][i].X][1-c]=w+adj[u][i].Y;
                pq.emplace(-w-adj[u][i].Y,1-c,adj[u][i].X);
            }
        }
    }
    printf("%d",d[t][1]);
}
