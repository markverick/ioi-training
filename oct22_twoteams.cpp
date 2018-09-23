#include<bits/stdc++.h>
using namespace std;
int color[100135],a[100135],b[100135];
vector<int> ls;
/// -1 = untouched, 0 = WHITE, 1 = BLACK
vector<int> adj[100135];
queue<int> q;
int main()
{
    int n,m,i,j,k,u,fu=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
    }
    int fst=1,lst=m,mid,mc=0;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;fu=0;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
            color[i]=3;
        }
        for(i=1;i<=mid;i++)
        {
            adj[a[i]].emplace_back(b[i]);
            adj[b[i]].emplace_back(a[i]);
            color[a[i]]=-1;
            color[b[i]]=-1;
        }
        for(i=1;i<=n;i++)
        {
            if(color[i]!=-1)
                continue;
            q.emplace(i);
            color[i]=0;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                for(j=0;j<adj[u].size();j++)
                {
                    if(color[adj[u][j]]==-1)
                    {
                        color[adj[u][j]]=1-color[u];
                        q.emplace(adj[u][j]);
                    }
                    else if(color[adj[u][j]]==color[u])
                    {
                        fu=1;
                        break;
                    }
                }
                if(fu==1)
                    break;
            }
            while(!q.empty())
                q.pop();
            if(fu==1)
                break;
        }
        if(fu==1)
        {
            lst=mid-1;
        }
        else
        {
            mc=max(mc,mid);
            fst=mid+1;
        }
    }
    printf("%d",mc);
}
