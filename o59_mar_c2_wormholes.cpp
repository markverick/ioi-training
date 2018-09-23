#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
pair<long long,long long> a[33],b[33];
long long adj[33][33],d[33][33];
long long dist(pair<long long,long long> p,pair<long long,long long> q)
{
    return abs(p.X-q.X)+abs(p.Y-q.Y);
}
int main()
{
    long long i,j,k,n,Q;
    pair<long long,long long> p,q;
    scanf("%lld %lld",&n,&Q);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld %lld",&a[i].X,&a[i].Y,&b[i].X,&b[i].Y);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            adj[i][j]=min(min(dist(a[i],a[j]),dist(b[i],b[j])),min(dist(a[i],b[j]),dist(b[i],a[j])));
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            d[i][j]=1000000000000000000;
        }
    }
    for(i=1;i<=n;i++)
    {
        d[i][i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            d[i][j]=adj[i][j];
            d[j][i]=adj[i][j];
        }
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                    d[i][j]=d[i][k]+d[k][j];
            }
        }
    }
    long long mn;
    while(Q--)
    {
        mn=1000000000000000000;
        scanf("%lld %lld %lld %lld",&p.X,&p.Y,&q.X,&q.Y);
        mn=dist(p,q);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                mn=min(mn,min(dist(p,a[i]),dist(p,b[i]))+min(dist(q,a[j]),dist(q,b[j]))+d[i][j]);
            }
        }
        printf("%lld\n",mn);
    }
}
