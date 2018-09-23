#include<bits/stdc++.h>
using namespace std;
int h[1135],w[1135],jum[1135],W;
int n;
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx>n)
    {
        return 0;
    }
    int mn=1000000000,mc=0,sum=0;
    int i;
    sum=0;
    for(i=idx;i<=n;i++)
    {
        mc=max(mc,h[i]);
        sum+=w[i];
        if(sum<=W)
        {
            mn=min(mn,dp(i+1)+mc);
        }
        else
            break;
    }
    return jum[idx]=mn;
}
int main()
{
    int i,j,k,a,b;
    while(scanf("%d %d.%d",&n,&a,&b)!=EOF)
    {
        W=a*10000+b;
        if(n==0&&W==0)
            return 0;
        memset(jum,-1,sizeof jum);
        for(i=1;i<=n;i++)
        {
            scanf("%d.%d",&a,&b);
            h[i]=a*10000+b;
            scanf("%d.%d",&a,&b);
            w[i]=a*10000+b;

        }
        printf("%d.%04d\n",dp(1)/10000,dp(1)%10000);
    }
}
