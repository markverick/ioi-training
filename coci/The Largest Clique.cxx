#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int state[1005],rt,mat[1005][1005],p[1005],hsh[1005];
vector<int> adj[1005];
int Find(int x)
{
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
}
int Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    p[x]=y;
}
void dfs(int idx)
{
    if(idx!=rt)
        mat[rt][idx]=1,mat[idx][rt]=1;
    state[idx]=1;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])continue;
        dfs(adj[idx][i]);
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,T,a,b,mc;
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d %d",&n,&m);
        mc=0;
        memset(mat,0,sizeof mat);
        memset(hsh,0,sizeof hsh);
        for(i=1;i<=n;i++)
            p[i]=i;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
        }
        for(i=1;i<=n;i++)
        {
            rt=i;
            memset(state,0,sizeof state);
            dfs(i);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(Find(i)!=Find(j))
                    Union(i,j);
            }
        }
        for(i=1;i<=n;i++)
        {
            hsh[Find(i)]++;
            mc=max(mc,hsh[Find(i)]);
        }
        printf("%d\n",mc);
    }
}
