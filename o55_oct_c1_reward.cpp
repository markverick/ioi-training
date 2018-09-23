#include<bits/stdc++.h>
using namespace std;
long long a[500135];
int main()
{
    long long n,m,i,j,k;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long fst=1,lst=2500000000000,mid,sum,mn=4500000000000;
    while(fst<=lst)
    {
        sum=0;
        mid=(fst+lst)/2;
//        printf("%lld <- %lld -> %lld",fst,mid,lst);
        for(i=1;i<=n;i++)
        {
            sum+=ceil((double)a[i]/mid);
        }
        if(sum<=m)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    printf("%lld",mn);
}
