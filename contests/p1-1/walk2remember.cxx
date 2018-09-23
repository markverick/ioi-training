#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> adj[200135];
vector<int> adjT[200135];
int n,m,k=0;
int sum[200135];
int out[200135];
int state[200135];
vector<int> topo;
vector<vector<int> > group;
void dfs(int idx)
{
    int i;
    state[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]]==0)
            dfs(adj[idx][i]);
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
    int i,j,a,b;
   // freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        a,b;
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
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
            adjT[adj[i][j]].emplace_back(i);
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
    {
        if(group[i].size()>1)
        for(j=0;j<group[i].size();j++)
        {
            out[group[i][j]]=1;
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",out[i]);
    }
}
