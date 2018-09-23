#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100135];
queue<int> q;
int color[100135];
int main()
{
    int T,m,n,i,j,k,a,b,u,fu=0;
    scanf("%d",&T);
    while(T--)
    {
        for(i=0;i<=100000;i++)
            adj[i].clear();
        memset(color,-1,sizeof color);
        fu=0;
        scanf("%d %d",&n,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        q.emplace(a);
        color[a]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(i=0;i<adj[u].size();i++)
            {
                if(color[adj[u][i]]==-1)
                {
                    color[adj[u][i]]=1-color[u];
                    q.emplace(adj[u][i]);
                }
                else if(color[adj[u][i]]==color[u])
                {
                    fu=1;
                    break;
                }
            }
            if(fu==1)
                break;
        }
        if(fu==1)
            printf("no\n");
        else
            printf("yes\n");
        while(!q.empty())
            q.pop();
    }
}
