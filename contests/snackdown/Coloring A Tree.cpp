#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;
vector<int> adj[55];
int fac[55];
int dp(int idx,int p,int used,int color,int srs)
{
    if(color<0)return 0;
    int i,j,k,sum=0,fu=0;
    for(i=0;i<adj[idx].size();i++)
    {
        if(adj[idx][i]!=p)
        {
            fu=1;
            break;
        }
    }
//    printf("%d %d %d %d %d\n",idx,p,used,color,fu);
    if(fu==0)
    {
        if(srs==1)
        {
            if(color!=0)return 0;
            return 1;
        }
        else
        {
            if(color<0)return 0;
            return 1;
        }
    }
    if(used==0)
    {
        for(i=0;i<adj[idx].size();i++)
        {
            if(adj[idx][i]==p)
                continue;
            for(j=i+1;j<adj[idx].size();j++)
            {
                if(i==j||adj[idx][j]==p)
                    continue;
                for(k=0;k<=color;k++)
                {
                    sum+=dp(adj[idx][i],idx,1,k,1)*dp(adj[idx][j],idx,1,color-k,0);sum%=1000000007;
                }
            }
        }
    }
    int fk=0;
    if(used<=1)
    {
        for(i=0;i<adj[idx].size();i++)
        {
            if(adj[idx][i]==p)
                continue;
            for(j=i+1;j<adj[idx].size();j++)
            {
                if(adj[idx][j]==p)
                    continue;
                fk=1;
                for(k=0;k<color;k++)
                {
                    sum+=(color)*dp(adj[idx][i],idx,1,k,1)*dp(adj[idx][j],idx,0,color-k-1,0);sum%=1000000007;
                    sum+=(color)*dp(adj[idx][i],idx,0,k,1)*dp(adj[idx][j],idx,1,color-k-1,0);sum%=1000000007;
                }
                for(k=0;k<color-1;k++)
                {
                    sum+=(color-1)*(color)*dp(adj[idx][i],idx,0,k,1)*dp(adj[idx][j],idx,0,color-k-2,0);sum%=1000000007;
                }
            }
        }
        if(fk==0)
        for(i=0;i<adj[idx].size();i++)
        {
            if(adj[idx][i]==p)
                continue;
            sum+=dp(adj[idx][i],idx,1,color,srs);sum%=1000000007;
            sum+=color*dp(adj[idx][i],idx,0,color-1,srs);sum%=1000000007;
        }
    }
    return sum;
}
int main()
{
    int T,i,j,k,n,m,a,b;
    scanf("%d",&T);
    fac[0]=1;
    fac[1]=1;
    for(i=2;i<=55;i++)
    {
        fac[i]=fac[i-1]*i;
        fac[i]%=1000000007;
    }
    while(T--)
    {
        scanf("%d %d",&n,&m);
        for(i=0;i<=n;i++)
        {
            adj[i].clear();
        }
        for(i=1;i<n;i++)
        {
            scanf("%d %d",&a,&b);
            adj[a].emplace_back(b);
            adj[b].emplace_back(a);
        }
        printf("%d\n",(m*dp(1,0,0,m-1,0))%1000000007);
    }
}
