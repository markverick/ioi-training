#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<pair<int,int> > adj[200135],adt[200135];
int state[200135],G;
vector<int> topo;
vector<int> grp[200135];
void dfs(int idx)
{
    state[idx]=1;
    for(int i=0;i<adt[idx].size();i++)
    {
        if(state[adt[idx][i].X])
            continue;
        dfs(adt[idx][i].X);
    }
    topo.emplace_back(idx);
}
void scc(int idx)
{
    state[idx]=1;
    grp[G].emplace_back(idx);
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i].X])
            continue;
        scc(adj[idx][i].X);
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,a,b;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[i].emplace_back(a,b);
        adt[a].emplace_back(i,b);
    }
    for(i=1;i<=n;i++)
    {
        if(state[i])continue;
        dfs(i);
    }
    memset(state,0,sizeof state);
    G=0;
    for(i=topo.size()-1;i>=0;i--)
    {
        if(state[topo[i]])continue;
        G++;
        scc(topo[i]);
    }
    for(i=1;i<=G;i++)
    {
        for(j=0;j<grp[i].size();j++)
            printf("%d ",grp[i][j]);
        printf("\n");
    }

}
