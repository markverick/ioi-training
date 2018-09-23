#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
int dp[3][10035],qs[3][10035];
int main()
{
	int n,c,i,j,k;
	scanf("%d %d",&n,&c);
    dp[1][0]=1;
    for(i=0;i<=c;i++)
        qs[1][i]=1;
	for(i=2;i<=n;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(j-i>=0)
                dp[i%2][j]=qs[(i-1)%2][j]-qs[(i-1)%2][j-i];
            else
                dp[i%2][j]=qs[(i-1)%2][j];
            while(dp[i%2][j]<0)
                dp[i%2][j]+=M;
            dp[i%2][j]%=M;
        }
        for(j=0;j<=c;j++)
            qs[i%2][j]=qs[i%2][j-1]+dp[i%2][j],qs[i%2][j]%=M;
    }
    printf("%d",dp[n%2][c]);
}
