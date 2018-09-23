#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
vector<tuple<int,int,int> > adj[100135];
int W[200135];
int state[200135],mn=1000000000,Max=0,n,m;
vector<int> path;
vector<pair<int,int> > edge;
void dfs(int idx)
{
    int v,e,dir,i;
    for(i=0;i<adj[idx].size();i++)
    {
        tie(v,e,dir)=adj[idx][i];
        if(state[e])
            continue;
        state[e]=1;
        swap(adj[idx][i],adj[idx][adj[idx].size()-1]);
        adj[idx].pop_back();
        dfs(v);
        edge.emplace_back(e,dir);
        path.emplace_back(idx);
    }
    if(path.size()==0)
    {
        path.emplace_back(idx);
    }
}
int main()
{
    int i,j,k,a,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        Max+=c;
        adj[a].emplace_back(b,i,1);
        adj[b].emplace_back(a,i,0);
        W[i]=c;
    }
    dfs(1);
    a=0;b=0;
    vector<int> aa,bb;
    for(i=0;i<edge.size();i++)
    {
        if(edge[i].Y==0)
        {
            aa.emplace_back(edge[i].X);
            a+=W[edge[i].X];
        }
        else
        {
            bb.emplace_back(edge[i].X);
            b+=W[edge[i].X];
        }
    }
    if(a<=b)
    {
        printf("%d\n",aa.size());
        for(i=0;i<aa.size();i++)
        {
            printf("%d\n",aa[i]);
        }
    }
    else
    {
        printf("%d\n",bb.size());
        for(i=0;i<bb.size();i++)
        {
            printf("%d\n",bb[i]);
        }
    }
}
