#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long n,ar[100135],a[333],b[333],c[333],d[333],blk,dp[333],mic[333][6];
// a [] b () c [) d (]
void update(long long i)
{
    long long j;
    memset(dp,0,sizeof dp);
    dp[0]=ar[i*blk];
    dp[1]=ar[i*blk+1];
    for(j=2;j<blk;j++)
        dp[j]=max(dp[j-2]+ar[i*blk+j],dp[j-1]);
    a[i]=dp[blk-1];
    c[i]=dp[blk-2];
    memset(dp,0,sizeof dp);
    dp[1]=ar[i*blk+1];
    for(j=2;j<blk;j++)
        dp[j]=max(dp[j-2]+ar[i*blk+j],dp[j-1]);
    b[i]=dp[blk-2];
    d[i]=dp[blk-1];
}
int main()
{
    long long m,i,j,x,y,p,q,tm;
    scanf("%lld %lld",&n,&m);
    blk=ceil(sqrt(n));
//    printf("%d\n",blk);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&ar[i] );
    }
    for(i=0;i<=(n-1)/blk;i++)
    {
        update(i);
//        printf("%d %d %d %d\n",a[i],b[i],c[i],d[i]);
    }
    long long mc=0,sum=0;
    while(m--)
    {
        scanf("%lld %lld",&x,&y);
        x--;
        ar[x]=y;
        update(x/blk);
        memset(mic,0,sizeof mic);
        mic[0][1]=max(a[0],d[0]);
        mic[0][2]=max(b[0],c[0]);
        mic[0][3]=max(b[0],c[0]);
        mic[0][4]=max(a[0],d[0]);
        tm=(n-1)/blk;
        for(i=1;i<=tm;i++)
        {
            mic[i][1]=max(mic[i-1][2],mic[i-1][3])+a[i];
            mic[i][2]=max(mic[i-1][1],mic[i-1][4])+b[i];
            mic[i][3]=max(mic[i-1][2],mic[i-1][3])+c[i];
            mic[i][4]=max(mic[i-1][1],mic[i-1][4])+d[i];
        }
        mic[tm][1]+=max(0ll,-a[tm]+c[tm]);
        mic[tm][4]+=max(0ll,-d[tm]+b[tm]);
		mic[tm][2]+=max(0ll,-b[tm]+d[tm]);
		mic[tm][3]+=max(0ll,-c[tm]+a[tm]);
        mc=0;
        for(i=1;i<=4;i++)
        {
            mc=max(mc,mic[tm][i]);
        }
     //   printf("%d\n",mc);
        sum+=mc;
    }
    printf("%lld",sum);
}