#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<int> adj[10135];
vector<int> adjT[10135];
vector<pair<int,int> > adG[10135];
vector<pair<int,int> > ::iterator it;
int gnai[10135];
int n,m,k=0,p,q;
int sum[10135],Min[10135];
int state[10135];
vector<int> topo,v;
char s[10135];
int ord[10135];
string item[10135];
string jum[10135];
vector<pair<vector<int>,int> > order;
vector<vector<pair<char,int> > > group;
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
    group[k].emplace_back(s[idx],idx);
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
string dp(int idx)
{
    if(!jum[idx].empty())
        return jum[idx];
    int i;
    string str,yo;
    str=item[idx];
    if(idx==gnai[n])
    {
        return str;
    }
    int mc=-1;
    string mn;
    for(i=0;i<adG[idx].size();i++)
    {
        yo=dp(adG[idx][i].Y);
        if(mc<(int)yo.size())
        {
            mc=yo.size();
            mn=yo;
        }
        else if(mc==yo.size())
        {
            mn=min(mn,yo);
        }
    }
    str+=mn;
    return jum[idx]=str;
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
    vector<pair<char,int> > blank;
    k=0;
    for(i=topo.size()-1;i>=0;i--)
    {
        if(state[topo[i]]==0)
        {
            group.push_back(blank);
            css(topo[i]);k++;
        }
    }
    vector<int> vec;
    for(i=0;i<group.size();i++)
    {
        vec.clear();
        sort(group[i].begin(),group[i].end());
        for(j=0;j<group[i].size();j++)
        {
            item[i]+=(char)group[i][j].X;
            vec.emplace_back(group[i][j].X);
            gnai[group[i][j].Y]=i;
//            printf("%c ",item[i][j]);
        }
        sort(item[i].begin(),item[i].end());
        order.emplace_back(vec,i);
//        printf("\n");
    }
    sort(order.begin(),order.end());
    for(i=0;i<order.size();i++)
    {
        ord[order[i].Y]=i;
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            adG[gnai[i]].emplace_back(ord[gnai[adj[i][j]]],gnai[adj[i][j]]);
        }
    }
    for(i=0;i<group.size();i++)
    {
        sort(adG[i].begin(),adG[i].end());
        it=unique(adG[i].begin(),adG[i].end());
        adG[i].resize(distance(adG[i].begin(),it));
    }
    memset(state,0,sizeof state);
    string strout=dp(gnai[1]);
    cout << strout;
}
