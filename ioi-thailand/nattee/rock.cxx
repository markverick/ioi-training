#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[55],jum[55][55][3];
int dp(int fs,int ls,int ch)
{
    if(jum[fs][ls][ch]>=0)return jum[fs][ls][ch];
    if(fs==ls)
    {
        if(ch)
            return a[fs];
        return 0;
    }
    if(ch)
        return jum[fs][ls][ch]=max(dp(fs+1,ls,1-ch)+a[fs],dp(fs,ls-1,1-ch)+a[ls]);
    return jum[fs][ls][ch]=max(dp(fs+1,ls,1-ch),dp(fs,ls-1,1-ch));
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	memset(jum,-1,sizeof jum);
	scanf("%d",&n);
	for(i=1;i<=n*2;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",dp(1,n*2,1));
}
