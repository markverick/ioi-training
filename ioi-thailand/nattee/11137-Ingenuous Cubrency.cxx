#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long jum[10135][24];
long long dp(long long x,long long bd)
{
    if(jum[x][bd]>=0)
        return jum[x][bd];
    if(x==0)
    {
        return 1;
    }
    if(bd==0)
        return 0;
    long long sum=0,i,tr=bd*bd*bd;
    for(i=x;i>=0;i-=tr)
    {
        sum+=dp(i,bd-1);
    }
    return jum[x][bd]=sum;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long n,i,j,k;
	memset(jum,-1,sizeof jum);
	while(scanf("%lld",&n)!=EOF)
    {
        printf("%lld\n",dp(n,21));
    }
}
