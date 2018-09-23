#include<bits/stdc++.h>
#define MI 1000000000
#define M 1000000007
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int dp[3][10135],a[10135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,prod=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		if(i==1||i==n)
		{
			if(a[i]>0)
			{
				printf("0");
				return 0;
			}
			a[i]=0;
		}
	{
	}
	dp[1][0]=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]==-1)
			for(j=0;j<=10000;j++)
		{
			{
				dp[i%2][j]= ((j-1>=0?dp[(i+1)%2][j-1]:0)+dp[(i+1)%2][j+1])%M+dp[(i+1)%2][j];
				dp[i%2][j]%=M;
			}
		}
		else
		{
			memset(dp[i%2],0,s			dp[i%2][a[i]]=((a[i]-1>=0?dp[(i+1)%2][a[i]-1]:0)+dp[(i+1)%2][a[i]])%M+dp[(i+1)%2][a[i]+1];
			dp[i%2][a[i]]%=M;
		}
	}
	printf("%d",dp[n%2][0]);
}