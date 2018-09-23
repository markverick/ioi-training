#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100135];
int indeg[100135];
queue<int> q;
vector<int> v;
vector<pair<int,int> > order;
int main()
{
    int n,m,i,j,k,a,b,u;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        indeg[b]++;
    }
    for(i=1;i<=n;i++)
    {
        if(indeg[i]==0)
        {
            q.emplace(i);
        }
    }
    while(!q.empty())
    {
        u=q.front();
        v.emplace_back(u);
        q.pop();
        for(i=0;i<adj[u].size();i++)
        {
            indeg[adj[u][i]]--;
            if(indeg[adj[u][i]]==0)
                q.emplace(adj[u][i]);
        }
    }
    if(v.size()!=n)
    {
        printf("no\n");
    }
    else
    {
        for(i=0;i<v.size();i++)
            printf("%d\n",v[i]);
    }
}
