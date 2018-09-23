#include<bits/stdc++.h>
using namespace std;
int Max[222],Min[222];
int adj[444][444],out[222],result[444],state[444],n,ck=1;
void dfs(int idx,int C)
{
    int i;
    if(idx==n*2+1)
    {
        for(i=1;i<C;i++)
        {
            adj[result[i]][result[i+1]]=0;
            adj[result[i+1]][result[i]]=1;
        }
        ck=1;
        return;
    }
    state[idx]=1;
    for(i=0;i<=n*2+1;i++)
    {
        if(adj[idx][i]==0)
            continue;
        if(state[i])
            continue;
        result[C+1]=i;
        dfs(i,C+1);
        if(ck==1)
            return;
    }
}
int main()
{
    int m,i,j,k,ch,a,b,c;
    scanf("%d %d",&n,&m);
    for(i=0;i<=201;i++)
        Min[i]=1000000000,Max[i]=-1;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&ch,&a,&b,&c);
        if(a<0||a>n||b<0||b>n)
        {
            printf("-1");
            return 0;
        }
        if(ch==1)
        {
            for(j=a;j<=b;j++)
                Max[j]=max(Max[j],c);
        }
        else
        {
            for(j=a;j<=b;j++)
                Min[j]=min(Min[j],c);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(Max[i]==-1)
            Max[i]=n;
        if(Min[i]==1000000000)
            Min[i]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(Min[i]>Max[i])
        {
            printf("-1");
            return 0;
        }
    }
    for(i=1;i<=n;i++)
        adj[0][i]=1;
    for(i=n+1;i<=n*2;i++)
        adj[i][n*2+1]=1;
    for(i=1;i<=n;i++)
    {
        for(j=Min[i];j<=Max[i];j++)
        {
            adj[i][n+j]=1;
        }
    }
//    for(i=1;i<=n;i++)
//    {
//        for(j=n+1;j<=n*2;j++)
//        {
//            printf("%d ",adj[i][j]);
//        }
//        printf("\n");
//    }
    ck=1;
    result[1]=0;
    while(ck==1)
    {
        ck=0;
        memset(state,0,sizeof state);
        dfs(0,1);
    }
    for(i=1;i<=n;i++)
    {
        for(j=n+1;j<=n*2;j++)
        {
//            if(adj[j][i])
//                printf("%d -> %d\n",i,j-n);
            if(adj[j][i])
                out[i]=j-n;
        }
    }

    for(i=1;i<=n;i++)
    {
        printf("%d ",out[i]);
    }
}
