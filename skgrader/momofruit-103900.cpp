#include<bits/stdc++.h>
using namespace std;
long long a[120000];
long long qs[120000];
int n;
int jum[120000];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==n)
        return 0;
    int mc=0;
    int i,j;
    for(i=idx+1;i<=n;i++)
    {
        if(qs[i]-qs[idx]>0)
            mc=max(mc,dp(i)+1);
    }
    return jum[idx]=mc;

}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    memset(jum,-1,sizeof jum);
    printf("%d\n",dp(0));
}

