#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1135],jum[1135][1135],n;
int dp(int idx,int amp)
{
	if(jum[idx][amp]>=0)return jum[idx][amp];
	if(idx==n)
		return 0;
	int mn=MI;
	if(idx+amp+1<=n)
		mn=min(mn,dp(idx+amp+1,amp+1)+a[idx+amp+1]);
	if(idx-amp>=1)
		mn=min(mn,dp(idx-amp,amp)+a[idx-amp]);
	return jum[idx][amp]=mn;
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
	printf("%d\n",dp(2,1)+a[2]);
}