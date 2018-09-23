#include<bits/stdc++.h>
using namespace std;
int T,t,h,f;
int n[2135];
int dp[2135][2135];
int hsh[2135][2135];
int mc[2135];
int main()
{
    int i,j,k,b,tt;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&t,&h,&f);
        memset(dp,0,sizeof dp);
        memset(hsh,0,sizeof hsh);
        memset(mc,0,sizeof mc);
        for(i=1;i<=t;i++)
        {
            scanf("%d",&n[i]);
            //a[i].emplace_back(0);
            for(j=1;j<=n[i];j++)
            {
                scanf("%d",&b);
                hsh[i][b]++;
                //a[i].emplace_back(b);
            }

//            sort(a[i].begin(),a[i].end());
        }

        for(i=h;i>=0;i--)
        {
            for(j=1;j<=t;j++)
            {
                if(i+f<=h)
                    dp[i][j]=max(dp[i+1][j]+hsh[j][i],hsh[j][i]+mc[i+f]);
                else
                    dp[i][j]=dp[i+1][j]+hsh[j][i];
                mc[i]=max(mc[i],dp[i][j]);
            }
        }
        int hi=0;
        for(i=1;i<=t;i++)
        {
            hi=max(hi,dp[0][i]);
            //printf("%d\n",dp[0][i]);
        }
        printf("%d\n",hi);
    }
}
