#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[500135],adk[500135],v;
int indeg[500135];
int hsh[500135];
queue<int> q;
vector<vector<int> >scc;
vector<int> emp;
vector<pair<int,int> > order;
void dfs(int idx)
{
    //printf("F");
    hsh[idx]=1;
    for(int i=0;i<adk[idx].size();i++)
    {
        if(hsh[adk[idx][i]])
            continue;
        dfs(adk[idx][i]);
    }
    scc[scc.size()-1].emplace_back(idx);
}
void dep(int idx)
{
    hsh[idx]=1;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(hsh[adj[idx][i]])
            continue;
        dep(adj[idx][i]);
    }
    v.emplace_back(idx);
}
int main()
{
    int i,j,k,u,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adk[b].emplace_back(a);
        indeg[b]++;
    }
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.emplace(i);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(hsh[i])
            continue;
        dep(i);
    }
    memset(hsh,0,sizeof hsh);
    //printf("%d\n",v.size());
    for(i=v.size()-1;i>=0;i--)
    {
        if(hsh[v[i]]==1)
            continue;
        scc.emplace_back(emp);
        dfs(v[i]);
    }
    for(i=0;i<scc.size();i++)
    {
        sort(scc[i].begin(),scc[i].end());
        order.emplace_back(scc[i][0],i);
    }
    sort(order.begin(),order.end());
    //printf("%d\n",scc.size());
    for(i=0;i<order.size();i++)
    {
        for(j=0;j<scc[order[i].second].size();j++)
        {
            printf("%d ",scc[order[i].second][j]);
        }
        printf("\n");
    }
}
