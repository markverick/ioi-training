#include<bits/stdc++.h>
using namespace std;
int color[100135];
/// 0 = untouched, 1 = undecided, 2 = WHITE, 3 = BLACK
/// -1 = untouched, 0 = WHITE, 1 = BLACK
queue<int> q;
vector<int> adj[100135];
int main()
{
    int n,m,i,j,k,u,a,b,fu=0;
    memset(color,-1,sizeof color);
    scanf("%d %d",&n,&m);
    scanf("%d %d",&a,&b);
    color[a]=1;color[b]=0;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
    for(i=2;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        if(fu>0)
            continue;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        if(color[a]>=0&&color[b]>=0)
        {
            if(color[a]==color[b])
                fu=i;
        }
        else if(color[a]>=0&&color[b]<0)
        {
            q.emplace(a);
            while(!q.empty())
            {
                u=q.front();
                q.pop();
                for(j=0;j<adj[u].size();j++)
                {
                    if(color[adj[u][j]]==-1)
                    {
                        color[adj[u][j]]=1-color[u];
                        q.emplace(adj[u][j]);
                    }
                    else
                    {
                        if(color[adj[u][j]]==color[u])
                        {
                            fu=i;break;
                        }
                    }
                }
                if(fu>0)break;
            }
            while(!q.empty())q.pop();
        }
        else if(color[a]<0&&color[b]>=0)
        {
            q.emplace(b);
            while(!q.empty())
            {
                u=q.front();
                q.pop();
                for(j=0;j<adj[u].size();j++)
                {
                    if(color[adj[u][j]]==-1)
                    {
                        color[adj[u][j]]=1-color[u];
                        q.emplace(adj[u][j]);
                    }
                    else
                    {
                        if(color[adj[u][j]]==color[u])
                        {
                            fu=i;break;
                        }
                    }
                }
                if(fu>0)
                    break;
            }
            while(!q.empty())q.pop();
        }
    }
    if(fu>0)
        printf("%d",fu-1);
    else
        printf("%d",m);
}
