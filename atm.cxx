#include<bits/stdc++.h>
using namespace std;
vector<int> adj[500135];
//vector<int> adjG[500135];
vector<int> adjT[500135];
int money[500135];
int n,m,k=0;
int start;
int pubN;
int sum[500135];
int isPub[500135];
int isPubG[500135];
int pubLst[500135];
int state[500135];
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
    if(isPub[idx]==1)
        isPubG[k]=1;
    group[k].emplace_back(idx);
}
int main()
{
    int i,j,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        a,b;
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&money[i]);
    }
    scanf("%d %d",&start,&pubN);
    for(i=1;i<=pubN;i++)
    {
        scanf("%d",&pubLst[i]);
        isPub[pubLst[i]]=1;
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
        group.push_back(blank);
        if(state[topo[i]]==0)
        {
            css(topo[i]);k++;
        }


    }
    for(i=0;i<group.size();i++)
    {
        for(j=0;j<group[i].size();j++)
        {
            sum[i]+=money[group[i][j]];
        }
        printf("%d\n",sum[i]);
    }
    int total=0;
    for(i=group.size()-1;i>=0;i--)
    {
        if(isPubG[i]==1)
        {
            for(i=0;i<=i;i++)
            {
                total+=sum[i];
            }
            break;
        }
    }
    printf("%d",total);
}
