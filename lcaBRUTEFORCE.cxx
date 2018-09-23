#include<bits/stdc++.h>
using namespace std;
int c[1135],a,p[1135],sp[50][1135],h[1135];
vector<int> adj[1135];
void dfs(int idx)
{
    for(int i=0;i<adj[idx].size();i++)
        h[adj[idx][i]]=h[idx]+1,
        dfs(adj[idx][i]);
}
int main()
{
    int n,i,j,k,m,x,y,T,t=1;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case %d:\n",t++);
        memset(h,0,sizeof h);
        for(i=0;i<=1005;i++)
            adj[i].clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            p[i]=i;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
            for(j=1;j<=c[i];j++)
            {
                scanf("%d",&a);
                adj[i].emplace_back(a);
                p[a]=i;
            }
        }
        dfs(1);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            while(x!=y)
            {
                if(h[x]==h[y])
                    x=p[x],y=p[y];
                else if(h[x]>h[y])
                    x=p[x];
                else
                    y=p[y];
            }
            printf("%d\n",x);
        }
    }
}
