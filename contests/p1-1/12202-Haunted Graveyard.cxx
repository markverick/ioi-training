#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long r,c,g,e;
long long maps[35][35];
long long t[35][35];
long long dist[35][35];
long long dx[6]={1,-1,0,0};
long long dy[6]={0,0,-1,1};
vector<pair<pair<long long,long long>,long long> > adj[35][35];
pair<long long,long long> go[35][35];
int main()
{
    long long i,j,k,l,a,b,aa,bb,fu;
    while(scanf("%lld %lld",&r,&c)!=EOF)
    {
        fu=0;
        memset(maps,0,sizeof maps);
        memset(t,0,sizeof t);
        memset(go,0,sizeof go);
        if(r==0&&c==0)
            return 0;
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                adj[i][j].clear();
                dist[i][j]=2000000000000000000;
                maps[i][j]=1;
            }
        }
        dist[1][1]=0;
        scanf("%lld",&g);
        for(i=1;i<=g;i++)
        {
            scanf("%lld %lld",&a,&b);
            a++;b++;
            maps[a][b]=0;
        }
        scanf("%lld",&e);
        for(i=1;i<=e;i++)
        {
            scanf("%lld %lld %lld %lld",&a,&b,&aa,&bb);
            a++;b++;aa++;bb++;
            scanf("%lld",&t[a][b]);
            maps[a][b]=2;
            go[a][b]=make_pair(aa,bb);
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                for(k=0;k<4;k++)
                {
                    if(maps[i][j]==1)
                    {
                        if(maps[i+dx[k]][j+dy[k]]!=0)
                            adj[i][j].emplace_back(make_pair(i+dx[k],j+dy[k]),1);
                    }
                    else if(maps[i][j]==2)
                    {
                        adj[i][j].emplace_back(go[i][j],t[i][j]);
                    }
                }
            }
        }
        for(l=1;l<=r*c;l++)
        {
            for(i=1;i<=r;i++)
            {
                for(j=1;j<=c;j++)
                {
                    for(k=0;k<adj[i][j].size();k++)
                    {
                        if(dist[i][j]+adj[i][j][k].Y<dist[adj[i][j][k].X.X][adj[i][j][k].X.Y])
                            dist[adj[i][j][k].X.X][adj[i][j][k].X.Y]=dist[i][j]+adj[i][j][k].Y;
                    }
                }
            }
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                for(k=0;k<adj[i][j].size();k++)
                {
                    if(dist[i][j]+adj[i][j][k].Y<dist[adj[i][j][k].X.X][adj[i][j][k].X.Y])
                        fu=1;
                }
            }
        }
        if(fu==1)
        {
            printf("Never\n");
        }
        else if(dist[r][c]==2000000000000000000)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("%lld\n",dist[r][c]);
        }
    }
}
