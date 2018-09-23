#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1000135],jum[1000135],n;
int dp(int idx)
{
	if(idx>n)return MI;
	if(jum[idx]>=0)return jum[idx];
	if(idx==n)return 0;
	int mn=MI;
	return jum[idx]=min(dp(idx+1),dp(idx+a[idx]))+1;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	memset(jum,-1,sizeof jum);
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
	printf("%d\n",dp(1));
}