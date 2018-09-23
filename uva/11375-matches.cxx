#include<bits/stdc++.h>
using namespace std;
int n,dp[2222][2222],a[12]={6,2,5,5,4,5,6,3,7,6};
int main()
{
    freopen("out.txt","w",stdout);
    int i,j,k,fu=1;
    dp[0][0]=1;
    for(i=0;i<=2000;i++) //digit
    {
        for(j=0;j<2000;j++) //matches
        {
            if(i>0)
                fu=0;
            for(k=fu;k<=9;k++)
            {
                dp[i+1][j+a[k]]+=dp[i][j];
            }
        }
    }
    int sum=0;
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        for(i=1;i<=2000;i++)
        {
            for(j=1;j<=n;j++)
                sum+=dp[i][j];
        }
        printf("%d\n",sum);
    }
}
