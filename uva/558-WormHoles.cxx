#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<pair<int,int> > adj[1135];
vector<pair<int,int> > adk[1135];
vector<int> adjT[1135];
int n,m,k=0,fu=0;
int dist[1135];
int sum[1135];
int state[1135];
int G[1135],chk[1135];
vector<int> topo;
vector<vector<int> > group;
void dfs(int idx)
{
    int i;
    state[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i].X]==0)
            dfs(adj[idx][i].X);
    }
    state[idx]=2;
    topo.emplace_back(idx);
}
void css(int idx)
{
    int i;
    state[idx]=1;
    for(i=0;i<adjT[idx].size();i++)
    {
        if(state[adjT[idx][i]]==0)
            css(adjT[idx][i]);
    }
    state[idx]=2;
    group[k].emplace_back(idx);
}
int main()
{
    int i,j,a,b,c,T,l;
//    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            adk[i].clear();
            adjT[i].clear();
            dist[i]=1000000000;
        }
        k=0;fu=0;
        topo.clear();group.clear();
        memset(sum,0,sizeof sum);
        memset(state,0,sizeof state);
        memset(G,0,sizeof G);
        memset(chk,0,sizeof chk);
        for(i=1;i<=m;i++)
        {
            a,b;
            scanf("%d %d %d",&a,&b,&c);
            a++;b++;
            adj[a].emplace_back(b,c);
        }
        for(i=1;i<=n;i++)
        {
            if(state[i]==0)
                dfs(i);
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<adj[i].size();j++)
            {
                adjT[adj[i][j].X].emplace_back(i);
            }
        }
        memset(state,0,sizeof state);
        vector<int> blank;
        k=0;
        for(i=topo.size()-1;i>=0;i--)
        {
            if(state[topo[i]]==0)
            {
                group.push_back(blank);
                css(topo[i]);k++;
            }
        }
        for(i=0;i<group.size();i++)
            for(j=0;j<group[i].size();j++)
                G[group[i][j]]=i;
        for(i=1;i<=n;i++)
        {
            for(j=0;j<adj[i].size();j++)
            {
                if(G[i]==G[adj[i][j].X])
                {
                    adk[i].emplace_back(adj[i][j]);
                }
            }
        }
        fu=0;

        for(i=0;i<group.size();i++)
        {
            dist[group[i][0]]=0;
            for(l=0;l<group[i].size();l++)
            {
                for(j=0;j<group[i].size();j++)
                {
                    a=group[i][j];
                    for(k=0;k<adk[a].size();k++)
                    {
                        b=adk[a][k].X;
                        if(dist[a]+adk[a][k].Y<dist[b])
                        {
                            dist[b]=dist[a]+adk[a][k].Y;
                        }
                    }
                }
            }
            for(j=0;j<group[i].size();j++)
            {
                a=group[i][j];
                for(k=0;k<adk[a].size();k++)
                {
                    b=adk[a][k].X;
                    if(dist[a]+adk[a][k].Y<dist[b])
                    {
                        fu=1;break;
                    }
                }
                if(fu==1)
                    break;
            }
            if(fu==1)
                break;
        }
        if(fu==1)
        {
            printf("possible\n");
        }
        else
        {
            printf("not possible\n");
        }
    }
}
