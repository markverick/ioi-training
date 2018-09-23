#include<bits/stdc++.h>
#define PB emplace_back
#define X first
#define Y second
using namespace std;
vector<int> adj[500005];
vector<int> group[500005];
stack<int> stk;
bool chk[500005];
int num[500005];
int low[500005];
pair<int,int> order[500005];
int T=1,C=1,S,P,n,m;
bool state[500005];
int d[500005];
inline void dfs(int idx)
{
    num[idx]=low[idx]=T++;
    stk.emplace(idx);
    chk[idx]=1;
    int i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(num[adj[idx][i]]==0)
        {
            dfs(adj[idx][i]);
            low[idx]=min(low[idx],low[adj[idx][i]]);
        }
        else if(chk[adj[idx][i]]==1)
        {
            low[idx]=min(low[idx],num[adj[idx][i]]);
        }
    }
    if(low[idx]==num[idx])
    {
        while(!stk.empty()&&stk.top()!=idx)
        {
            group[C].PB(stk.top());
            chk[stk.top()]=0;
            stk.pop();
        }
        if(!stk.empty())
        {
            group[C].PB(stk.top());
            chk[stk.top()]=0;
            stk.pop();
        }
        C++;
    }
    state[idx]=1;
}

int main()
{
    int i,j,k,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].PB(b);
    }
    for(i=1;i<=n;i++)
    {
        if(state[i]==0)
            dfs(i);
    }
    for(i=1;i<C;i++)
        sort(group[i].begin(),group[i].end());
    for(i=1;i<C;i++)
    {
        order[i]=make_pair(group[i][0],i);
    }
    sort(&order[1],&order[C]);
    for(i=1;i<C;i++)
    {
        for(j=0;j<group[order[i].Y].size();j++)
        {
            printf("%d ",group[order[i].Y][j]);
        }
        printf("\n");
    }
}
