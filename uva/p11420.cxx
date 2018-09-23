#include<bits/stdc++.h>
using namespace std;
long long jum[80][80][3];
long long dp(long long idx,long long locked,long long unlock)
{
    if(jum[idx][locked][unlock]>=0)
        return jum[idx][locked][unlock];
    if(idx==0)
    {
        if(locked==0)
            return 1;
        else
            return 0;
    }
    long long sum=0;
    if(unlock)
    {
        sum+=dp(idx-1,locked,1);
        sum+=dp(idx-1,locked,0);
    }
    else
    {
        if(locked-1>=0)
            sum+=dp(idx-1,locked-1,0);
        sum+=dp(idx-1,locked,1);
    }
    return jum[idx][locked][unlock]=sum;
}
int main()
{
    long long n,s;
    memset(jum,-1,sizeof jum);
    while(scanf("%lld %lld",&n,&s)!=EOF)
    {
        if(n<0&&s<0)
            return 0;
        printf("%lld\n",dp(n,s,0) );
    }
}
