#include<bits/stdc++.h>
using namespace std;
vector<int> adj[18];
int mat[18][18],n,jum[70000];
int dp(int bit)
{
    if(jum[bit]>=0)
        return jum[bit];
    int i,j;
    int hsh[18][18];
    memset(hsh,0,sizeof hsh);
    for(i=1;i<=n;i++)
    {
        if((bit|(1<<(i-1)))==bit)
        {
            for(j=0;j<adj[i].size();j++)
            {
                hsh[i][adj[i][j]]=1;
                hsh[adj[i][j]][i]=1;
            }
        }
    }
    int mn=1000000000,fu=0;
    for(i=1;i<=n;i++)
    {
        if((bit|(1<<(i-1)))!=bit)
        {
            for(j=0;j<adj[i].size();j++)
            {
                if(hsh[i][adj[i][j]]==0)
                {
                    fu=1;
                    mn=min(mn,dp(bit|(1<<(i-1)))+1);
                    break;
                }
            }
        }
    }
    if(fu==0)
        return 0;
    return jum[bit]=mn;
}
int main()
{
    int i,j,k,a,b,t=0;
    while(scanf("%d",&n)!=EOF)
    {
        t++;
        memset(jum,-1,sizeof jum);
        if(n==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            adj[i].clear();
        }
        memset(mat,0,sizeof mat);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            for(j=1;j<=a;j++)
            {
                scanf("%d",&b);
                b++;
                mat[i][b]=1;
                mat[b][i]=1;
            }
        }
        for(i=1;i<=n;i++)
        {
            mat[i][i]=1;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(mat[i][j]==0)
                {
                    adj[i].emplace_back(j);
                }
            }
        }
        printf("Case %d: %d\n",t,n-dp(0));
    }
}
