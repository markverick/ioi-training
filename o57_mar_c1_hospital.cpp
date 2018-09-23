#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100135];
queue<int> q;
int Sum[100135],n,state[100135],p[100135],num[100135],Min[100135];
void dfs(int idx)
{
    int fu=0,i,sum=0,cot=0,S=0,N=0;
    state[idx]=1;
    num[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(state[adj[idx][i]])
            continue;
        p[adj[idx][i]]=idx;
        dfs(adj[idx][i]);
        fu=1;
        num[idx]+=num[adj[idx][i]];
        Sum[idx]+=Sum[adj[idx][i]]+num[adj[idx][i]];
    }
    if(fu==0)
    {
        num[idx]=1;
        return;
    }
}
void dep(int idx)
{
    int fu=0,i,sum=0;
    for(i=0;i<adj[idx].size();i++)
    {
        if(p[idx]==adj[idx][i])
            continue;
        Min[adj[idx][i]]=Min[idx]+n-num[adj[idx][i]]-num[adj[idx][i]];
        dep(adj[idx][i]);
    }
}
int main()
{
    int i,j,k,a,b,u;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    dfs(1);
    Min[1]=Sum[1];
    memset(state,0,sizeof state);
    dep(1);
    int mn=2000000000;
    for(i=1;i<=n;i++)
    {
        mn=min(mn,Min[i]);
    }
    printf("%d",mn);
}
