#include<bits/stdc++.h>
using namespace std;
int x[100135],y[100135],fu=0;
vector<int> adj[100135];
int n,state[100135];
void dfs(int idx)
{
    state[idx]=1;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==idx)continue;
        if(state[adj[idx][i]]==1)
        {
            //printf("%d\n",idx);
            fu=1;break;
        }
        dfs(adj[idx][i]);
    }
    state[idx]=2;
}
int main()
{
    int T,i,j,k,a,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);fu=0;
        memset(state,0,sizeof state);
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);x[a]=i;
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);y[a]=i;
        }
        for(i=1;i<=n;i++)
        {
            adj[x[i]].emplace_back(y[i]);
        }
        for(i=1;i<=n;i++)
        {
            if(state[i]==0)
                dfs(i);
        }
        if(fu==0)
            printf("YES\n");
        else
            printf("NO\n");
        for(i=1;i<=n;i++)
            adj[i].clear();
    }
}
