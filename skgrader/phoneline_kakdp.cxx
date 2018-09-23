#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int n,p,k;
vector<pair<int,int> >adj[1135];
//v w
int jum[1135][1135];
int dp(int idx,int free)
{
    if(jum[idx][free]>=0)
        return jum[idx][free];
    int mn=1000000000,i;
    printf("%d %d\n",idx,free);
    for(i=0;i<adj[idx].size();i++)
    {
        mn=min(mn,dp(adj[idx][i].X,free)+adj[idx][i].Y);
        if(free<k)
            mn=min(mn,dp(adj[idx][i].X,free+1));
    }
    return jum[idx][free]=mn;
}
int main()
{
    int i,j,k,a,b,c;
    scanf("%d %d %d",&n,&p,&k);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=p;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }
    printf("%d",dp(n,0));
}

