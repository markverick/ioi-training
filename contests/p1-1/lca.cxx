#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,m,a,b,x,y;
int pos[1135],h[1135],p[1135],A[1135];
vector<int> adj[1135];
vector<pair<int,int> > lca[1135];
int color[1135],out[1135];
int Find(int idx)
{
    if(p[idx]==idx)
        return idx;
    return p[idx]=Find(p[idx]);
}
void Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(h[x]<h[y])
    {
        p[x]=y;
        h[x]=max(h[x]+1,h[y]);
    }
    else
    {
        p[y]=x;
        h[y]=max(h[y]+1,h[x]);
    }
}
void dfs(int u,int p)
{
    int i;
    p[u]=u;A[u]=u;
    for(i=0;i<adj[u].size();i++)
    {
        if(adj[u][i]==p)
        {
            dfs(adj[u][i],u);
            Union(u,v)
            A[Find(u)]=u;
        }
    }
    color[u]=1;
    for(i=0;i<lca[u].size();i++)
    {
        if(color[lca[u][i].X]==1)
            out[lca[u][i].Y]=A[Find(lca[u][i].X)];
    }
}
int main()
{
    int i,j,k,t,T,Q,tmp;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(pos,0,sizeof pos);
        memset(p,0,sizeof p);
        memset(A,0,sizeof A);
        for(i=0;i<=1000;i++)
            adj[i].clear();
        printf("Case %d:\n",t);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            for(j=1;j<=a;j++)
            {
                scanf("%d",&b);
                adj[i].emplace_back(b);
            }
        }
        scanf("%d",&Q);
        for(i=1;i<=Q;i++)
        {
            scanf("%d %d",&x,&y);
            lca[x].emplace_back(y,i);
            lca[y].emplace_back(x,i);
        }
        dfs(1,1);
        for(i=1;i<=Q;i++)
        {
            printf("%d\n",out[i]);
        }
    }
}
