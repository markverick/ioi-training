#include<bits/stdc++.h>
using namespace std;
int a[1135],dp[1135][1135],p[1135][1135];
int main()
{
//    freopen("out.txt","w",stdout);
    int n,i,j,k,l,cost,mn,m;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        memset(dp,0,sizeof dp);
        memset(p,0,sizeof p);
        a[1]=0;
        for(i=2;i<=n+1;i++)
        {
            scanf("%d",&a[i]);
        }
        a[n+2]=m;
        for(l=1;l<=n+1;l++)
        {
            for(i=1;i<=n+1;i++)
            {
                j=i+l-1;
                if(j>n+1)
                    break;
                if(l==1)
                {
                    dp[i][j]=0,p[i][j]=i;
                    continue;
                }
                mn=1000000000;
                for(k=p[i][j-1]+1;k<=p[i+1][j]+1;k++)
                {
                    cost=dp[i][k-1]+dp[k][j]+a[j+1]-a[i];
                    if(cost<mn)
                    {
                        mn=cost;
                        p[i][j]=k-1;
                    }
                }
                dp[i][j]=mn;
            }
        }
//        for(i=1;i<=n+2;i++)
//        {
//            for(j=1;j<=n+2;j++)
//            {
//                printf("%2d ",dp[i][j]);
//            }
//            printf("%d\n");
//        }
        printf("%d\n",dp[1][n+1]);
    }
}
