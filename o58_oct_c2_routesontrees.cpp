#include<bits/stdc++.h>
#define X first
#define Y second
#define EB emplace_back
#define MP make_pair
#define MAX_INT 100000000000000000
using namespace std;
vector<pair<long long,long long> > adj[100135];
long long n,m,k;
long long d[100135][10];
priority_queue<tuple<long long,long long,long long> >pq;
///weight idx jump
int main()
{
    long long i,j,a,b,c,w,u,jeb;
    scanf("%lld %lld %lld",&n,&m,&k);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=k+1;j++)
            d[i][j]=MAX_INT;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        adj[a].EB(b,c);
    }
    pq.emplace(0,1,0);
    d[1][0]=0;
    while(!pq.empty())
    {
        tie(w,u,jeb)=pq.top();
        w=-w;
        pq.pop();
        for(i=0;i<adj[u].size();i++)
        {
            if(adj[u][i].Y>=0)
            {
                if(d[adj[u][i].X][jeb]>w+adj[u][i].Y)
                {
                    d[adj[u][i].X][jeb]=w+adj[u][i].Y;
                    pq.emplace(-w-adj[u][i].Y,adj[u][i].X,jeb);
                }
            }
            else if(adj[u][i].Y<0&&adj[u][i].Y>=-100)
            {
                if(d[adj[u][i].X][jeb]>w)
                {
                    d[adj[u][i].X][jeb]=w;
                    pq.emplace(-w,adj[u][i].X,jeb);
                }
            }
            else if(jeb<k)
            {
                if(d[adj[u][i].X][jeb+1]>w)
                {
                    d[adj[u][i].X][jeb+1]=w;
                    pq.emplace(-w,adj[u][i].X,jeb+1);
                }
            }
        }
    }
    long long mn=MAX_INT;
    for(i=0;i<=k;i++)
    {
        mn=min(mn,d[n][i]);
    }
    if(mn!=MAX_INT)
        printf("%lld",mn);
    else
        printf("-1");
}
