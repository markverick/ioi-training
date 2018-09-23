#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[1531][1531],jum[1531][1531],n;
int dp(int L,int R)
{
	if(jum[L][R]>=0)return jum[L][R];
	if(L==n||R==n)
		return 0;
	int cur=max(L,R)+1;
	return jum[L][R]=min(dp(cur,R)+maps[cur][L],dp(L,cur)+maps[cur][R]);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			scanf("%d",&maps[i][j]);
	}
	printf("%d",dp(1,1));
}