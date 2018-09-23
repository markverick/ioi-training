#include<bits/stdc++.h>
using namespace std;
long long a[222];
int main()
{
    long long n,i,j,k,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]--;
        }
        long long fst=0,mid,lst=1000000000000000135,mc=0,sum;
        while(fst<=lst)
        {
            sum=0;
            mid=(fst+lst)/2;
            for(i=1;i<=n;i++)
            {
                if(mid>a[i])
                {
                    sum+=mid-a[i];
                    if(sum>mid)
                        break;
                }
            }
            if(sum<=mid)
            {
                mc=max(mc,mid);
                fst=mid+1;
            }
            else
            {
                lst=mid-1;
            }
        }
        printf("%lld\n",mc+1);
    }
}
