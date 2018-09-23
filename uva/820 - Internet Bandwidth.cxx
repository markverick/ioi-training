#include<bits/stdc++.h>
using namespace std;
int adj[135][135],bb,n;
int result[135],st,ed,chk=0;
int state[135];
void dfs(int idx,int c,int mn)
{
    int i;
    if(idx==ed)
    {
        for(i=1;i<c;i++)
        {
            adj[result[i-1]][result[i]]-=mn;
            adj[result[i]][result[i-1]]+=mn;
        }
        chk=1;
        return;
    }
    state[idx]=1;
    for(i=1;i<=n;i++)
    {
        if(i==idx||state[i])
            continue;
        if(adj[idx][i]>0&&adj[idx][i]>=bb)
        {
            result[c]=i;
            dfs(i,c+1,min(mn,adj[idx][i]));
            if(chk==1)
                return;
        }
    }
}
int main()
{
    int T,t=0,i,j,k,m,a,b,c,mc=0,sum;
    while(scanf("%d",&n)!=EOF)
    {
        t++;
        if(n==0)
            return 0;
        sum=0;mc=0;
        memset(adj,0,sizeof adj);
        memset(state,0,sizeof state);
        memset(result,0,sizeof result);
        scanf("%d %d %d",&st,&ed,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d %d",&a,&b,&c);
            adj[a][b]+=c;
            adj[b][a]+=c;
            mc=max(mc,c);
        }
        for(i=1;i<=n;i++)
        {
            sum-=adj[ed][i];
        }
        result[0]=st;
        bb=mc/2;
        while(bb>=1)
        {
            chk=1;
            while(chk==1)
            {
                chk=0;
                memset(state,0,sizeof state);
                dfs(st,1,mc);
            }
            bb/=2;
        }
        for(i=1;i<=n;i++)
        {
            sum+=adj[ed][i];
        }
        printf("Network %d\nThe bandwidth is %d.\n\n",t,sum);
    }
}
