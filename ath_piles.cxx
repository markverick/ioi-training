#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int pas[111][111],jum[111][111],n,m;
int dp(int idx,int num)
{
	if(jum[idx][num]>=0)return jum[idx][num];
	if(num==0)
		return 1;
	int sm=0,i;
	for(i=m;i<=num;i++)
		sm+=dp(idx+1,num-i)*pas[num-i][i-1],sm%=9871;
	return jum[idx][num]=sm;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int T,i,j,k;
	for(i=0;i<=100;i++)
		pas[i][0]=1,pas[0][i]=1;
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
			pas[i][j]=pas[i-1][j]+pas[i][j-1],pas[i][j]%=9871;
	scanf("%d",&T);
	while(T--)
	{
		memset(jum,-1,sizeof jum);
		scanf("%d %d",&n,&m);
		printf("%d\n",dp(1,n));
	}

}