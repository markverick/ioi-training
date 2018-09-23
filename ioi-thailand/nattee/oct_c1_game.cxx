#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<int> adj[5135],adt[5135],adG[5135],topo,grp[5135];
int ste[5135],G=0,gnai[5135],hsh[5135];
void dfs(int idx)
{
    ste[idx]=1;
    for(int i=0;i<adt[idx].size();i++)
    {
        if(ste[adt[idx][i]])continue;
        dfs(adt[idx][i]);
    }
    topo.emplace_back(idx);
}
void scc(int idx)
{
    gnai[idx]=G;
    grp[G].emplace_back(idx);
    for(int i=0;i<adj[idx].size();i++)
    {
        if(gnai[adj[idx][i]])continue;
        scc(adj[idx][i]);
    }
}
int dp(int idx,int p)
{
    int mc=0,i;
    for(i=0;i<adG[idx].size();i++)
    {
        if(adG[idx][i]==idx||adG[idx][i]==p)continue;
        mc=max(mc,dp(adG[idx][i],idx));
    }
    return mc+1;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d %d",&a,&b),adj[a].emplace_back(b),adt[b].emplace_back(a);
    for(i=0;i<n;i++)
    {
        if(ste[i])continue;
        dfs(i);
    }
    memset(ste,0,sizeof ste);
    for(i=topo.size()-1;i>=0;i--)
    {
        if(gnai[topo[i]])continue;
        G++;
        scc(topo[i]);
    }
    for(i=0;i<n;i++)
        for(j=0;j<adt[i].size();j++)
            adG[gnai[i]].emplace_back(gnai[adt[i][j]]);
    for(i=1;i<=G;i++)
    {
        hsh[dp(i,0)]+=grp[i].size();
    }
    for(i=1;i<=G;i++)
    {
        if(!hsh[i])break;
        printf("%d ",hsh[i]);
    }
}
