#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char s[10135];
vector<pair<int,int> > adj[10135];
vector<pair<int,int> > adk[10135];
int state[10135];
int fwd[10135],bwd[10135],n;
void dfsf(int idx)
{
    if(idx==n)
        return;
    int i;
    state[idx]=1;
    fwd[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i].Y])
            continue;
        dfsf(adj[idx][i].Y);
    }
}
void dfsb(int idx)
{
    if(idx==1)
        return;
    int i;
    state[idx]=1;
    bwd[idx]=1;
    for(i=0;i<adk[idx].size();i++)
    {
        if(state[adk[idx][i].Y])
            continue;
        dfsb(adk[idx][i].Y);
    }
}
int main()
{
    int m,i,j,k,x,y,a,b,all=0;
    scanf("%d %d",&n,&m);
    scanf("%s",s+1);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(s[b]-'A',b);
        adk[b].emplace_back(s[a]-'A',a);
    }
    for(i=1;i<=n;i++)
    {
        sort(adj[i].begin(),adj[i].end());
        sort(adk[i].begin(),adk[i].end());
    }
    dfsf(1);
    memset(state,0,sizeof state);
    dfsb(n);
    memset(state,0,sizeof state);
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",bwd[i],fwd[i]);
        if(bwd[i]==1&&fwd[i]==1)
        {
            all++;
        }
    }

}
