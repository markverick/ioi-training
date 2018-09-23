#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int G,s[200135],n;
int dp[200135][222],d[222][222];

int main()
{
    int i,j,k,T,m,W,a,b,g,c,fk;
    scanf("%d",&T);
    while(T--)
    {
        G=1;fk=0;
        scanf("%d %d %d",&W,&m,&n);
        for(i=0;i<=200002;i++)
            for(j=0;j<=201;j++)
                dp[i][j]=1000000000;
        for(i=0;i<=200;i++)
            for(j=0;j<=200;j++)
                d[i][j]=1;
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            d[a][b]=0;
            d[b][a]=0;
        }
        for(k=1;k<=W;k++)
        {
            for(i=1;i<=W;i++)
            {
                for(j=1;j<=W;j++)
                {
                    d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
                }
            }
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
        }
//        for(i=1;i<=W;i++)
//        {
//            for(j=1;j<=W;j++)
//            {
//                printf("%d ",d[i][j]);
//            }
//            printf("\n");
//        }
        for(i=0;i<=W;i++)
            dp[0][i]=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=W;j++)
            {
                if(j==s[i])dp[i][j]=dp[i-1][j];
                else if(d[s[i]][j]==0)
                    dp[i][j]=min(1000000000,dp[i-1][j]+1);
                else
                    dp[i][j]=1000000000;
            }
            for(j=2;j<=W;j++)
                dp[i][j]=min(dp[i][j],dp[i][j-1]);
        }
        if(dp[n][W]==1000000000)
            printf("-1\n");
        else
            printf("%d\n",dp[n][W]);

    }
}
