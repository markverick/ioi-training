#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> adj[100135];
vector<int> adjT[100135];
int grp[100135];
pair<int,int> order[100135];
int n,m,k=0;
int sum[100135];
int state[100135];
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
    int i,j,a,b,q;
   // freopen("in.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        for(j=1;j<=a;j++)
        {
            scanf("%d",&b);
            adj[i].emplace_back(b);
        }
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
        for(j=0;j<group[i].size();j++)
        {
            grp[group[i][j]]=i;
        }
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&a,&b);
        if(grp[a]==grp[b])
            printf("yes\n");
        else
            printf("no\n");
    }


}

