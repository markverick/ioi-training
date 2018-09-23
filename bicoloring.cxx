#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[222];
int state[222];
int dfs(int idx,int col)
{
    int mc=0;
    state[idx]=col;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]]==col)
            return 1;
        else if(state[adj[idx][i]])
            continue;
        mc=max(mc,dfs(adj[idx][i],3-col));
    }
    return mc;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,a,b;
	while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        scanf("%d",&m);
        memset(state,0,sizeof state);
        for(i=1;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            a++;b++;
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        int mc=0;
        for(i=1;i<=n;i++)
        {
            if(state[i])continue;
            mc=max(mc,dfs(i,1));
        }
        if(mc)
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");
    }
}
