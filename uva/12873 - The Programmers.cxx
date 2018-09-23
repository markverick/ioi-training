#include<bits/stdc++.h>
using namespace std;
int P,S,C,ck=1;
int adj[600][600],state[600],result[600];
void dfs(int idx,int cot,int mn)
{
    int i;
    if(idx==P+S+1)
    {
        for(i=1;i<cot;i++)
        {
            adj[result[i]][result[i+1]]-=mn;
            adj[result[i+1]][result[i]]+=mn;
        }
        ck=1;
        return;
    }
    state[idx]=1;
    for(i=0;i<=P+S+1;i++)
    {
        if(adj[idx][i]==0)
            continue;
        if(state[i])
            continue;
        result[cot+1]=i;
        dfs(i,cot+1,min(mn,adj[idx][i]));
        if(ck==1)
            return;
    }
}
int main()
{
    int m,i,j,k,a,b,T;
    scanf("%d",&T);
    while(T--)
    {
        memset(adj,0,sizeof adj);
        memset(result,0,sizeof result);
        scanf("%d %d %d %d",&P,&S,&C,&m);
        for(i=1;i<=P;i++)
            adj[0][i]=1;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a][P+b]=1;
        }
        for(i=P+1;i<=P+S;i++)
        {
            adj[i][P+S+1]=C;
        }
        ck=1;
        result[1]=0;
        while(ck==1)
        {
            ck=0;
            memset(state,0,sizeof state);
            dfs(0,1,1000000000);
        }
        int sum=0;
        for(i=P+1;i<=P+S;i++)
        {
            for(j=1;j<=P;j++)
            {
                if(adj[i][j]>0)
                {
                    sum++;
                }
            }
        }
        printf("%d\n",sum);
    }
}
