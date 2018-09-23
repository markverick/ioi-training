#include<bits/stdc++.h>
using namespace std;
long long a[100135];
int main()
{
    long long n,p,i;
    scanf("%lld %lld",&n,&p);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    long long fst=1,lst=2000000000ll,sum=0,mid,mn=1000000000000000000ll;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
       // prlong longf("%lld %lld %lld\n",fst,mid,lst);
        sum=0;
        for(i=1;i<=n;i++)
        {
            sum+=(mid+a[i]-1)/a[i];
        }
        if(sum>=p)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    printf("%lld",mn-1);
}
