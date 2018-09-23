#include<bits/stdc++.h>
#define MI 2000000000000000000
using namespace std;
long long x[100135],y[100135],dp[100135],a[]={0,1,2};
int main()
{
    long long i,j,k,n,cot,mn=MI,mnn,MN;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&x[i],&y[i]);
    }
    sort(&x[1],&x[n+1]);
    sort(&y[1],&y[n+1]);
    dp[1]=MI;
    if(y[1]!=x[1])
        dp[1]=abs(y[1]-x[1]);
    dp[2]=MI;
    if(x[1]!=y[1]&&x[2]!=y[2])
        dp[2]=min(dp[2],abs(x[1]-y[1])+abs(x[2]-y[2]));
    if(x[1]!=y[2]&&x[2]!=y[1])
        dp[2]=min(dp[2],abs(x[1]-y[2])+abs(x[2]-y[1]));
    for(i=3;i<=n;i++)
    {
        mn=MI;
        do
        {
            cot=0;
            for(j=0;j<3;j++)
            {
                if(abs(x[i-j]-y[i-a[j]]))
                    cot+=abs(x[i-j]-y[i-a[j]]);
                else
                {
                    cot=MI;break;
                }
            }
            mn=min(mn,cot);
        }
        while(next_permutation(&a[0],&a[3]));
        mnn=MI;
        if(x[i]!=y[i]&&x[i-1]!=y[i-1])
            mnn=min(mnn,abs(x[i]-y[i])+abs(x[i-1]-y[i-1]));
        if(x[i-1]!=y[i]&&x[i]!=y[i-1])
            mnn=min(mnn,abs(x[i-1]-y[i])+abs(x[i]-y[i-1]));
        if(x[i]!=y[i])
            MN=abs(x[i]-y[i]);
        else MN=MI;
        MN+=dp[i-1];
        MN=min(MN,dp[i-2]+mnn);
        MN=min(MN,dp[i-3]+mn);
        dp[i]=MN;
    }
    printf("%lld",dp[n]);
}
