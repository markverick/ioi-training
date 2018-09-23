#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[100135],topo;
int ste[100135];
int dfs(int idx)
{
    ste[idx]=1;
    for(int i=0;i<adj[idx].size();i++)
    {
        if(ste[adj[idx][i]]==2)
            continue;
        else if(ste[adj[idx][i]])
            return 1;
        if(dfs(adj[idx][i]))return 1;
    }
    topo.emplace_back(idx);
    ste[idx]=2;
    return 0;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,a,b;
	scanf("%d %d",&n,&m);
	for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
    }
    for(i=1;i<=n;i++)
    {
        if(ste[i])
            continue;
        if(dfs(i))
        {
            printf("no");
        }
    }
    for(i=topo.size()-1;i>=0;i--)
        printf("%d\n",topo[i]);
}
