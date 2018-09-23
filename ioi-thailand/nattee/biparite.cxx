#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[100135];
int col[100135];
int dfs(int idx,int c,int p)
{
    col[idx]=c;
//    printf("%d %d %d\n",idx,c,p);
    for(int i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==p)continue;
//        printf("> %d  %d %d\n",adj[idx][i],col[adj[idx][i]],c);
        if(col[adj[idx][i]]==-1)
        {
            if(dfs(adj[idx][i],1-c,idx))return 1;
        }
        else
        {
            if(col[adj[idx][i]]==c)
                return 1;
        }
    }
    return 0;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,T,a,b,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            adj[i].clear();
        memset(col,-1,sizeof col);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);

        }
        if(dfs(1,0,0))
            printf("no\n");
        else
            printf("yes\n");
    }
}
