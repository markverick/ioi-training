#include<bits/stdc++.h>
using namespace std;
int r,c,n,d;
int x[135],y[135],adj[222][222],state[222],result[222],ck=1;
int dist(int x,int y)
{
    return x*x+y*y;
}
void dfs(int idx,int cot)
{
    int i;
    if(idx==n+1)
    {
        for(i=1;i<cot;i++)
        {
            adj[result[i]][result[i+1]]--;
            adj[result[i+1]][result[i]]++;
        }
        ck=1;
        return;
    }
    state[idx]=1;
    for(i=0;i<=n+1;i++)
    {
        if(adj[idx][i]==0)
            continue;
        if(state[i])
            continue;
        result[cot+1]=i;
        dfs(i,cot+1);
        if(ck==1)
            return;
    }
}
int main()
{
//    freopen("out.txt","w",stdout);
    int i,j,k,T=0;
    while(scanf("%d %d %d %d",&r,&c,&n,&d)!=EOF)
    {
        if(r==0&&c==0&&n==0&&d==0)
            return 0;
        T++;
        memset(adj,0,sizeof adj);
        memset(result,0,sizeof result);
        for(i=1;i<=n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
        }
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(dist(x[i]-x[j],y[i]-y[j])<=4*d*d)
                {
                    adj[i][j]=1;
                    adj[j][i]=1;
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            if(y[i]<=d)
                adj[0][i]=1;
            if(c-y[i]<=d)
                adj[i][n+1]=1;
        }
        ck=1;
        while(ck==1)
        {
            ck=0;
            memset(state,0,sizeof state);
            dfs(0,1);
        }
        int sum=0;
        for(i=1;i<=n;i++)
        {
            if(adj[n+1][i]>0)
                sum++;
        }
        printf("Case %d: %d\n",T,sum);
    }
}
