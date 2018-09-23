#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[100135];
int h[100135];
void dfs(int idx,int pa)
{
    int i,mc=0;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]==pa)
            continue;
        fu=1
        mc=max(mc,dfs(adj[idx][i],idx));
    }
    h[idx]=mc+1;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,a,b;
	scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1,0);
}
