#include<bits/stdc++.h>
using namespace std;
int dp[135][20135],a[135];
//Number of item, Value of item
int main()
{
    int n,i,j,k,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]+=100;sum+=a[i];
    }
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=n/2;j>=0;j--)
        {
            for(k=20001;k>=0;k--)
            {
                if(dp[j][k])
                    dp[j+1][k+a[i]]=1;
            }
        }
    }
    int mn=1000000000;
    for(i=20001;i>=0;i--)
    {
        if(dp[n/2][i])
            mn=min(mn,abs(sum-i-i));
    }
    printf("%d",mn);
}
