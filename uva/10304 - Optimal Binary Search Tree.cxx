#include<bits/stdc++.h>
using namespace std;
int a[255],qs[255],dp[255][255],p[255][255];
int main()
{
//    freopen("out.txt","w",stdout);
    int n,i,j,k,l,cost,mn;
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof dp);
        memset(qs,0,sizeof qs);
        memset(p,0,sizeof p);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        qs[i]=0;
        for(i=1;i<=n;i++)
        {
            qs[i]=qs[i-1]+a[i];
        }
        for(l=1;l<=n;l++)
        {
            for(i=1;i<=n;i++)
            {
                j=i+l-1;
                if(l==1)
                {
                    dp[i][j]=0,p[i][j]=i;
                    continue;
                }
                mn=1000000000;
                for(k=p[i][j-1];k<=p[i+1][j];k++)
                {
                    cost=dp[i][k-1]+dp[k+1][j]+qs[j]-qs[i-1]-a[k];
                    if(cost<mn)
                    {
                        mn=cost;
                        p[i][j]=k;
                    }
                }
                dp[i][j]=mn;
            }
        }
        printf("%d\n",dp[1][n]);
    }
}
