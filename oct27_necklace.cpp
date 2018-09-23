#include<bits/stdc++.h>
using namespace std;
vector<int> adj[300135];
int indeg[300135];
void dfs(int idx)
{
    printf("%d ",idx);
    for(int i=adj[idx].size()-1;i>=0;i--)
        dfs(adj[idx][i]);
}
int main()
{
    int n,i,j,k,a,b;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[b].emplace_back(a);
        indeg[a]++;
    }
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            dfs(i);
            break;
        }
    }
}
