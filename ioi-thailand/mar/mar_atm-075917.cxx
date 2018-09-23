#include<stdio.h>
#include<string.h>
#include<set>
#include<vector>
using namespace std;
vector<int> adj[500135];
set<int> adjG[500135];
set<int> adjGT[500135];
vector<int> adjT[500135];
int money[500135];
int n,m,k=0;
int start;
int pubN;
int sum[500135];
int isPub[500135];
int isPubG[500135];
int groupNai[500135];
int pubLst[500135];
int state[500135];
vector<int> topo;
vector<vector<int> > group;
void dfs(int idx)
{
    int i;
    state[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]]==0)
            dfs(adj[idx][i]);
    }
    state[idx]=2;
    topo.emplace_back(idx);
}
void css(int idx)
{
    int i;
    state[idx]=1;
    for(i=0;i<adjT[idx].size();i++)
    {
        if(state[adjT[idx][i]]==0)
            css(adjT[idx][i]);
    }
    state[idx]=2;
    if(isPub[idx]==1)
        isPubG[k]=1;
    group[k].emplace_back(idx);
}
int findAsc(int idx)
{
    int mc=0;
    for(auto it=adjG[idx].begin();it!=adjG[idx].end();it++)
    {
        mc=max(mc,findAsc(*it)+sum[*it]);
    }
    return mc;
}
int findDsc(int idx)
{
    int mc=0;
    for(auto it=adjGT[idx].begin();it!=adjGT[idx].end();it++)
    {
        mc=max(mc,findDsc(*it)+sum[*it]);
    }
    return mc;
}
int main()
{
    int i,j,a,b;
   // freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        a,b;
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&money[i]);
    }
    scanf("%d %d",&start,&pubN);
    for(i=1;i<=pubN;i++)
    {
        scanf("%d",&pubLst[i]);
        isPub[pubLst[i]]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(state[i]==0)
            dfs(i);
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            adjT[adj[i][j]].emplace_back(i);
        }
    }
    memset(state,0,sizeof state);
    vector<int> blank;
    k=0;
    for(i=topo.size()-1;i>=0;i--)
    {

        if(state[topo[i]]==0)
        {
            group.push_back(blank);
            css(topo[i]);k++;
        }

    }
    for(i=0;i<group.size();i++)
    {
        for(j=0;j<group[i].size();j++)
        {
            sum[i]+=money[group[i][j]];
            groupNai[group[i][j]]=i;
          //  printf("%d ",group[i][j]);
        }
    //    printf("\n");
        //printf("%d\n",sum[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            adjG[groupNai[i]].insert(groupNai[adj[i][j]]);
            adjGT[groupNai[adj[i][j]]].insert(groupNai[i]);
        }
    }
    for(i=0;i<group.size();i++)
    {
        adjG[i].erase(i);
        adjGT[i].erase(i);
    }
    int highest=0;
   for(i=0;i<group.size();i++)
   {
   	if(isPubG[i]==0)
   		continue;
   	//printf("%d = %d\n",i,sum[i]+findDsc(i));
   		highest=max(highest,sum[i]+findDsc(i));
   }
   	 printf("%d",highest);
}