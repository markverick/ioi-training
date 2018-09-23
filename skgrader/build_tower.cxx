#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int n;
pair<long long,long long> a[220];
long long jum[220];
long long dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx==0)
    {
        return 0;
    }
    long long mc=0;
    for(int i=idx-1;i>=0;i--)
    {
        if(a[idx].Y>a[i].Y&&a[idx].X!=a[i].X)
            mc=max(mc,dp(i)+a[i].Y);
    }
    return jum[idx]=mc;
}
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&a[i].X,&a[i].Y);
        }
        sort(&a[1],&a[n+1]);
        a[n+1]=MP(1000000000000000005,1000000000000000005);
        memset(jum,-1,sizeof jum);
       // printf("%d\n",lower_bound(&a[0],&a[n],MP(x+1,0))-&a[0]);
        printf("%lld\n",dp(n+1));

    }
}
