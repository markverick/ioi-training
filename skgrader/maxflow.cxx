#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
#define MI 1000000000
using namespace std;
vector<int> adj[50135];
int s,t,n;
int state[50135];
int hsh[50135],result[50135];
vector<pair<int,int> > v;
inline void dfs(int idx,int cot,int p,int mul)
{
    int i;
    if(idx==t)
    {
        for(i=1;i<cot;i++)
        {
            hsh[result[i]]+=mul;
        }
        return;
    }
    state[idx]=1;
    for(i=0;i<adj[idx].size();i++)
    {
        if(p==adj[idx][i])
            continue;
        result[cot]=adj[idx][i];
        dfs(adj[idx][i],cot+1,idx,mul);
    }
}
int main()
{
//    freopen("maxflow.in","r",stdin);
//    freopen("maxflow.out","w",stdout);
    int i,j,k;
    int m,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&a,&b);
        adj[a].EB(b);
        adj[b].EB(a);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&s,&t);
        v.emplace_back(min(s,t),max(s,t));
    }
    sort(v.begin(),v.end());
    int cot=1;
    for(i=0;i<m;i++)
    {
        if(i==0||(v[i-1]!=v[i]) )
        {
            dfs(s,1,0,cot);
            hsh[s]+=cot;
            cot=1;
        }
        else
        {
            cot++;
        }
    }
    int mc=0;
    for(i=1;i<=n;i++)
    {
        mc=max(mc,hsh[i]);
    }
    printf("%d",mc);
}

