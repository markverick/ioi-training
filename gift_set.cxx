#include<bits/stdc++.h>
using namespace std;
long long a[300135];
int main()
{
    long long n,m,i,j,k,mac=0;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%lld",&a[i]);
        mac=max(mac,a[i]);
    }
    mac=max(mac,n);
    long long fst=0,mid,lst=1000000000000000000,sum=0,mn=1000000000000000000,mc=0;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        sum=0;
//        printf("%lld %lld %lld\n",fst,mid,lst);
        for(i=1;i<=m;i++)
        {
            sum+=(a[i]-1)/mid+1;
        }
        if(sum<=n)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
//    printf("%d\n",mn);
    long long Max=0;
    for(i=1;i<=m;i++)
    {
        if(a[i]>=mn)
            Max=mn;
        else
            Max=max(Max,a[i]);
    }
    printf("%lld",Max);
}
