#include<bits/stdc++.h>
using namespace std;
int n;
long long jum[1200][1200];
long long dp(int idx,int mc)
{
    //printf("%d %d\n",idx,mc);
    if(jum[idx][mc]>=0)
        return jum[idx][mc];

    if(idx==1)
    {
        return 1;
    }
    int i,j,k;
    unsigned long long sum=0;
    long long a=dp(idx-1,mc);
    sum+=mc*a;
    sum%=1000000007;

    sum+=dp(idx-1,mc+1);
    sum%=1000000007;
    /*for(i=mc;i<=mc+1;i++)
    {
        sum+=dp(idx-1,max(i,mc));
        sum%=1000000007;
    }*/
    return jum[idx][mc] = sum%1000000007;
}
int main()
{
    int T,t;
    int i,j,k;
    scanf("%d",&T);
    memset(jum,-1,sizeof jum);
    for(t=0;t<T;t++)
    {
        scanf("%d",&n);
        printf("%lld\n",dp(n,1)%1000000007);
    }
}
