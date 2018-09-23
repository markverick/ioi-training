#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> adj[10135];
vector<int> adjT[10135];
vector<pair<int,int> > adG[10135];
vector<pair<int,int> > ::iterator it;
int gnai[10135];
pair<int,int> order[10135];
int n,m,k=0,p,q;
int sum[10135],Min[10135];
int state[10135];
vector<int> topo,v;
char s[10135];
vector<vector<pair<int,int> > > group;
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
    group[k].emplace_back(s[idx]-'A',idx);
}
int def(int idx)
{
    if(idx==q)
    {
        v.emplace_back(idx);
        return 1;
    }
    state[idx]=1;
    int i;
    for(i=0;i<adG[idx].size();i++)
    {
        if(state[adG[idx][i].Y])
            continue;
        if(def(adG[idx][i].Y)==1)
        {
            v.emplace_back(idx);
            return 1;
        }
    }
    return 0;
}
int main()
{
    int i,j,a,b;
   // freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    scanf("%s",s+1);
    for(i=1;i<=m;i++)
    {
        a,b;
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
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
    vector<pair<int,int> > blank;
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
        Min[i]=1000000000;
        sort(group[i].begin(),group[i].end());
        for(j=0;j<group[i].size();j++)
        {
            Min[i]=min(Min[i],group[i][j].X);
//            printf("%d ",group[i][j].Y);
            gnai[group[i][j].Y]=i;
            if(group[i][j].Y==1)
                p=i;
            else if(group[i][j].Y==n);
                q=i;
        }
//        printf("\n");
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            adG[gnai[i]].emplace_back(Min[gnai[adj[i][j]]],gnai[adj[i][j]]);
        }
    }
    for(i=0;i<group.size();i++)
    {
        sort(adG[i].begin(),adG[i].end());
        it=unique(adG[i].begin(),adG[i].end());
        adG[i].resize(distance(adG[i].begin(),it));
    }
    memset(state,0,sizeof state);
    def(p);
    vector<char> out;
    for(i=v.size()-1;i>=0;i--)
    {
//        printf("%d > ",v[i]);
        for(j=0;j<group[v[i]].size();j++)
        {
            out.emplace_back('A'+group[v[i]][j].X);
        }
    }
//    printf("\n");
    for(i=0;i<out.size();i++)
        printf("%c",out[i]);
}
