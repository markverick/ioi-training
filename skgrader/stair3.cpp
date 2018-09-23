#include<bits/stdc++.h>
int n;
long long jum[70][3];
long long dp(int idx,int indy)
{
    if(jum[idx][indy]>=0)
        return jum[idx][indy];
    if(idx==n)
    {
        if(indy==1)
            return 1;
        else
        return 2;

    }
    if(idx>n)
    {
            return 0;
    }
    if(idx<0)
        return jum[idx][indy] = 0;
    if(indy==1)
        return jum[idx][indy] = dp(idx+1,1)+dp(idx+2,1)+dp(idx+3,1);
    else
        return jum[idx][indy] = dp(idx-1,1)+dp(idx+1,0)+dp(idx+2,0)+dp(idx+3,0);
}
int main()
{
    memset(jum,-1,sizeof jum);
    scanf("%d",&n);
    printf("%lld",dp(0,0));
}
