#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int state[1005],C=0,G=0,gnai[1005],mat[1005][1005],jum[1005];
vector<int> adj[1005],adt[1005],adg[1005],topo,grp[1005];
void dfs(int idx)
{
    state[idx]=1;
    for(int i=0;i<adt[idx].size();i++)
    {
        if(state[adt[idx][i]])continue;
        dfs(adt[idx][i]);
    }
    topo.emplace_back(idx);
}
void scc(int idx)
{
    state[idx]=1;
    gnai[idx]=G;
    grp[G].emplace_back(idx);
    for(int i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])
            continue;
        scc(adj[idx][i]);
    }
}
int dp(int idx,int pa)
{
    if(jum[idx]>=0)
        return jum[idx];
    int i,mc=0;
    for(i=0;i<adg[idx].size();i++)
    {
        if(i==adg[idx][i]||adg[idx][i]==pa)continue;
        mc=max(mc,dp(adg[idx][i],idx)+(int)(grp[adg[idx][i]].size()));
    }
    return jum[idx]=mc;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,T,a,b,mc,cot=0;
	scanf("%d",&T);
	while(T--)
    {
        scanf("%d %d",&n,&m);
        mc=0;cot=0;G=0;C=0;
        topo.clear();
        memset(mat,0,sizeof mat);
        memset(gnai,0,sizeof gnai);
        for(i=1;i<=n;i++)
            adj[i].clear(),adt[i].clear(),adg[i].clear(),grp[i].clear();
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
            adt[b].emplace_back(a);
        }
        memset(state,0,sizeof state);
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
//        for(i=1;i<=G;i++)
//        {
//            for(j=0;j<grp[i].size();j++)
//                printf("%d ",grp[i][j]);
//            printf("\n");
//        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<adj[i].size();j++)
            {
                if(gnai[i]!=gnai[adj[i][j]])
                {
                    mat[gnai[i]][gnai[adj[i][j]]]=1;
                }
            }
        }
        for(i=1;i<=G;i++)
        {
            for(j=1;j<=G;j++)
            {
                if(mat[i][j])
                    adg[i].emplace_back(j);
            }
        }
        mc=0;
        for(i=1;i<=G;i++)
        {
            memset(jum,-1,sizeof jum);
            mc=max(mc,dp(i,0)+(int)grp[i].size());
        }
        printf("%d\n",mc);
    }
}
