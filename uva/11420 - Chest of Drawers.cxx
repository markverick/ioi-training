#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long n,s;
long long jum[80][80][3];
long long dp(long long idx,long long lft,long long lck)
{
    if(jum[idx][lft][lck]>=0)
        return jum[idx][lft][lck];
    if(idx<=0)
    {
        if(lft==0)
            return 1;
        return 0;
    }
    long long sum=0;
    if(lck==1)
    {
        if(lft>=1)
            sum+=dp(idx-1,lft-1,1);
        sum+=dp(idx-1,lft,0);
    }
    else
    {
        sum+=dp(idx-1,lft,1);
        sum+=dp(idx-1,lft,0);
    }
    return jum[idx][lft][lck]=sum;
}
int main()
{
//	freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k;
    memset(jum,-1,sizeof jum);
	while(scanf("%lld %lld",&n,&s)!=EOF)
    {
        if(n<0&&s<0)
            return 0;
        printf("%lld\n",dp(n,s,1));
    }
}
