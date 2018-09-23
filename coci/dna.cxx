#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[1000135];
int dp[1000135][3];
int main()
{
	//freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int n,i,j,k;
	scanf("%d",&n);
	scanf("%s",str+1);
	for(i=1;i<=n;i++)
    {
        if(str[i]=='A')
            str[i]=0;
        else
            str[i]=1;
    }
	for(i=1;i<=n;i++)
    {
        for(j=0;j<=1;j++)
        {
            if(str[i]^j==0)
            {
                dp[i][j]=dp[i-1][j];
            }
            else
            {
                dp[i][j]=min(dp[i-1][j],dp[i-1][1-j])+1;
            }
        }
    }
    printf("%d",dp[n][0]);
}
