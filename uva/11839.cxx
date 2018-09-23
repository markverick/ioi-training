#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int state[2135];
vector<int> adj[2135];
int dfs(int idx)
{
    state[idx]=1;
    int i,sum=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])
            continue;
        sum+=dfs(adj[idx][i]);
    }
    return sum;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,a,b,c,fk;
	while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0)
            return 0;
        for(i=1;i<=n;i++)
            adj[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a].emplace_back(b);
            if(c==2)
                adj[b].emplace_back(a);
        }
        fk=0;
        for(i=1;i<=n;i++)
        {
            memset(state,0,sizeof state);
            if(dfs(i)!=n)
            {
                fk=1;break;
            }
        }
        printf("%d\n",1-fk);
    }
}
