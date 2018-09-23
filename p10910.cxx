#include<bits/stdc++.h>
using namespace std;int jum[100][100];
long long dp(long long w,long long idx)
{
    if(idx==0)
    {
        if(w==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(jum[w][idx]>=0)
        return jum[w][idx];
    long long sum=0,i;
    for(i=0;i<=w;i++)
    {
        sum+=dp(w-i,idx-1);
    }
    return jum[w][idx]=sum;
}
int main()
{
    long long C,n,t,p,i,j;
    scanf("%lld",&C);
    while(C--)
    {
        memset(jum,-1,sizeof jum);
        scanf("%lld %lld %lld",&n,&t,&p);
        t-=n*p;//t+=n-1;
        if(t<0)
        {
            printf("0\n");
            continue;
        }
        //printf("%lld %lld\n",t,n-1);
        printf("%lld\n",dp(t,n));
    }
}
