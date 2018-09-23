#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[10135];
int adk[10135][10135];
int d[10135],e[10135],Min,n,a[250135],b[250135],c[250135],hsh[250135];
priority_queue<pair<int,int> > pq;
int jum[10135];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==n)
    {
        return 1;
    }
    int sum=0,i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adk[idx][adj[idx][i].X]>0)
            sum+=adk[idx][adj[idx][i].X]*dp(adj[idx][i].X);
    }
    return jum[idx]=sum;
}
int main()
{
    int m,i,j,k,u,w;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(jum,-1,sizeof jum);
        memset(hsh,0,sizeof hsh);
        memset(adk,0,sizeof adk);
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        Min=1000000000;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
            a[i]++;b[i]++;
            adj[a[i]].emplace_back(b[i],c[i]);
            adj[b[i]].emplace_back(a[i],c[i]);
        }
        for(i=1;i<=n;i++)
            d[i]=1000000000;
        d[1]=0;
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
                    pq.emplace(-d[adj[u][i].X],adj[u][i].X);
                }
            }
        }
        for(i=1;i<=n;i++)
            e[i]=1000000000;
        e[n]=0;
        pq.emplace(0,n);
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
                    pq.emplace(-e[adj[u][i].X],adj[u][i].X);
                }
            }
        }
        Min=d[n];
        printf("%d\n",Min);
        for(i=1;i<=m;i++)
        {
            if(d[a[i]]+c[i]+e[b[i]]<=Min)
            {
                adk[a[i]][b[i]]++;
            }
        }
        printf("%d\n",dp(1)*Min);
    }
}
