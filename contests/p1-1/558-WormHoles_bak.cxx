#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long n,m;
long long dist[1135];
vector<pair<long long,long long> > adj[1135];
int main()
{
    long long i,j,k,l,a,b,c,fu,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld",&n,&m);
        fu=0;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            dist[i]=2000000000000000000;
        }
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a].emplace_back(b,c);
        }
        for(l=1;l<=n;l++)
        {
            for(i=1;i<=n;i++)
            {
                for(k=0;k<adj[i].size();k++)
                {
                    if(dist[i]+adj[i][k].Y<dist[adj[i][k].X])
                        dist[adj[i][k].X]=dist[i]+adj[i][k].Y;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            for(k=0;k<adj[i].size();k++)
            {
                if(dist[i]+adj[i][k].Y<dist[adj[i][k].X])
                    fu=1;
            }
        }
        if(fu==1)
        {
            printf("possible\n");
        }
        else if(dist[n]==2000000000000000000)
        {
            printf("not possible\n");
        }
    }
}

