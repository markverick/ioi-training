#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[5135],b[5135],hsh[5135],dp[5135];
map<int,int> mp;
bool cmp(int a,int b)
{
	return a<b;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,m,cot=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]),b[i]=a[i];
	sort(&b[0],&b[n],cmp);
	for(i=0;i<n;i++)
	{
		mp[b[i]]=i/m;
	}
	for(i=0;i<n;i++)
	{
		a[i]=mp[a[i]];
	}
	dp[0]=1;
	int mc=1;
	for(i=1;i<n;i++)
	{
		dp[i]=1;
		for(j=0;j<i;j++)
		{
			if(a[j]<=a[i])
				dp[i]=max(dp[i],dp[j]+1);
		}
		mc=max(mc,dp[i]);
	}
	printf("%d",n-mc);
}