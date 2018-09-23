#include<bits/stdc++.h>
using namespace std;
int n,adj[2135][2135],state[2135],chk;
int result[2135];
void dfs(int idx,int cot)
{
    int i;
    if(idx==n*3+1)
    {
        for(i=1;i<cot;i++)
        {
            adj[result[i-1]][result[i]]=0;
            adj[result[i]][result[i-1]]=1;
        }
        chk=1;
        return;
    }
    state[idx]=1;
    for(i=0;i<=n*3+1;i++)
    {
        if(state[i]||adj[idx][i]<=0)
            continue;
        result[cot]=i;
        dfs(i,cot+1);
        if(chk==1)
            return;
    }
}
int main()
{
    int T,a,b,i,j,t;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        memset(adj,0,sizeof adj);
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            adj[i][n+a]=1;
            adj[i][n*2+a]=1;
            adj[0][i]=1;
            adj[n+a][n*3+1]=1;
            adj[n*2+a][n*3+1]=1;
        }
        chk=1;
        result[0]=0;
        while(chk==1)
        {
            memset(state,0,sizeof state);
            chk=0;
            dfs(0,1);
        }
        int sum=0;
        for(i=n+1;i<=n*3;i++)
        {
            sum+=adj[n*3+1][i];
        }
        printf("%d\n",sum);
    }
}
