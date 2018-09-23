#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
unsigned long long jum[65][65];
unsigned long long trib(long long n,long long bk)
{
    if(n<=1)
        return 1;
    if(jum[n][bk]>0)
        return jum[n][bk];
    long long sum=1,i;
    for(i=1;i<=bk;i++)
    {
        if(n-i<=1)
            sum++;
        else
            sum+=trib(n-i,bk);
    }
    return jum[n][bk]=sum;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long a,b,i,j,k,t=1;
    memset(jum,0,sizeof jum);
	while(scanf("%lld %lld",&a,&b)!=EOF)
    {
        if(a>60)return 0;
        printf("Case %lld: %llu\n",t,trib(a,b));
        t++;
    }
}
