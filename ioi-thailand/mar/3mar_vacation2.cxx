#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[21000];
vector<pair<int,int> > adX[220];
vector<pair<int,int> > adi[21000];
int inted[21000];
int pos[21000];
int id[220];
int dist[220][220];
int main()
{
    int n,m,kk,q;
    scanf("%d %d %d %d",&n,&m,&kk,&q);
    int i,j,k;
    for(i=1;i<=m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
    }
    for(i=1;i<=kk;i++)
    {
        scanf("%d",&id[i]);
        inted[id[i]]=1;
        pos[id[i]]=i;
    }
    for(i=1;i<=m;i++)
    {
        for(j=0;j<adj[id[i]].size();j++)
        {
            if(inted[adj[id[i]][j].X])
                adX[i].emplace_back(pos[adj[id[i]][j].X],adj[id[i]][j].Y);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[id[i]].size();j++)
        {
            if(inted[adj[id[i]][j].X])
                adi[i].emplace_back(pos[adj[id[i]][j].X],adj[id[i]][j].Y);
        }
    }
    for(i=0;i<q;i++)
    {
        int a;
        scanf("%d %d",&a,&a);
        printf("TEST\n");
    }

}
