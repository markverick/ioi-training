#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],jum[100135],n;
int dp(int idx)
{
    if(jum[idx]>=0)return jum[idx];
    if(idx>=n)
        return 0;
    return jum[idx]=max(dp(idx+1),dp(idx+3)+a[idx+2]);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",dp(1));
}
