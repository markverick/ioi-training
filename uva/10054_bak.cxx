#include<bits/stdc++.h>
using namespace std;
int deg[70];
int hsh[70][70];
int n;
vector<pair<int,int> > path;
vector<int> adj[70];
void dfs(int idx,int num)
{
    int i;
    if(num==n)
    {
        //path.emplace_back(idx);
        return;
    }
    for(i=0;i<adj[idx].size();i++)
    {
        if(hsh[idx][adj[idx][i]]==0)
        {
            hsh[idx][adj[idx][i]]=1;
            hsh[adj[idx][i]][idx]=1;
            dfs(adj[idx][i],num+1);
            path.emplace_back(idx,adj[idx][i]);
        }
    }
    return;
}
int main()
{
    int T,t,i,j,k,a,b,c;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        if(t>1)
            printf("\n");
        scanf("%d",&n);
        memset(deg,0,sizeof deg);
        memset(hsh,0,sizeof hsh);
        path.clear();
        for(i=1;i<=50;i++)
        {
            adj[i].clear();
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
            deg[a]++;deg[b]++;
            c=a;
        }
        int fu=0;
        for(i=1;i<=50;i++)
        {
            if(deg[i]%2==1)
            {
                fu=1;
                break;
            }
        }
        if(fu==1)
        {
            printf("Case #%d\nsome beads may be lost\n",t);
        }
        else
        {
            printf("Case #%d\n",t);
            dfs(c,0);
            if(path.size()!=n)
            {
                printf("some beads may be lost\n");
            }
            else for(i=path.size()-1;i>=0;i--)
            {
                printf("%d %d\n",path[i].first,path[i].second);
            }
        }
    }
}
