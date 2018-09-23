#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> adj[10135],adt[10135];
int state[10135];
vector<int> topo;
vector<vector<int> > group;
void dfs(int idx)
{
    state[idx]=1;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(!state[adj[idx][i]])
            dfs(adj[idx][i]);
    }
    topo.emplace_back(idx);
}
void scc(int idx)
{
    state[idx]=1;
    for(int i=0;i<adt[idx].size();i++)
    {
        if(!state[adt[idx][i]])
            scc(adt[idx][i]);
    }
    group[group.size()-1].emplace_back(idx);
}
int main()
{
    int i,j,k,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adt[b].emplace_back(a);
    }
    for(i=1;i<=n;i++)
    {
        if(!state[i])
            dfs(i);
    }
    memset(state,0,sizeof state);
    vector<int> blank;
    for(i=topo.size()-1;i>=0;i--)
    {
        if(!state[topo[i]])
        {
            group.emplace_back(blank);
            scc(topo[i]);
        }
    }
    for(i=0;i<group.size();i++)
    {
        for(j=0;j<group[i].size();j++)
        {
            printf("%d ",group[i][j]);
        }
        printf("\n");
    }
}
