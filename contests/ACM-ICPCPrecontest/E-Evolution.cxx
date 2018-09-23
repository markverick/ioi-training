#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[1135];
int state[1135];
void dfs(int idx,int pa)
{
    state[idx]=1;
    int i;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])
        {
            state[adj[idx][i]]=2;
            continue;
        }
        dfs(adj[idx][i],idx);
    }
}
int main()
{
	int i,j,k,m,a,b,mc=0;
	scanf("%d",&m);
	for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
    }
    for(i=0;i<=999;i++)
    {
        memset(state,0,sizeof state);
        dfs(i,1000);
        if(state[i]==2)
            mc=max(mc,1);
    }
    if(mc)
        printf("BUG");
    else
        printf("OK");
}
