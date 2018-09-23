#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int adj[50][50],state[50],result[50],ck,n;
void dfs(int idx,int C)
{
    int i;
    if(idx==n*2+1)
    {
        int mn=100;
        for(i=1;i<C;i++)
        {
            mn=min(mn,adj[result[i-1]][result[i]]);
        }
        for(i=1;i<C;i++)
        {
            adj[result[i-1]][result[i]]-=mn;
            adj[result[i]][result[i-1]]+=mn;
        }
        printf("!!%d\n",mn);
        ck=1;
        return;
    }
    state[idx]=1;
    for(i=0;i<=n*2+1;i++)
    {
        if(idx==i||state[i])continue;
        if(adj[idx][i]==0)continue;
        result[C]=i;
        dfs(i,C+1);
        if(ck)
            return;
    }
}
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        adj[0][i]=100;
        adj[n+i][n*2+1]=100;
        for(j=1;j<=n;j++)
        {
            scanf("%d",&adj[i][n+j]);
        }
    }
    ck=1;
    result[0]=0;
    while(ck==1)
    {
        ck=0;
        memset(state,0,sizeof state);
        dfs(0,1);
        printf("%d %d %d\n",adj[0][2],adj[2][4],adj[4][5]);
    }
    int sum=0;
    for(i=n+1;i<=n*2;i++)
    {
        sum+=adj[n*2+1][i];
    }
    printf("%d",sum);
}
