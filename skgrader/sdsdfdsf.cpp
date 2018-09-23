#include<bits/stdc++.h>
using namespace std;
long long qs[1135],a[1135];
int main()
{
    long long n,i,j,k,mc,b;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    long long fst=0,sum=0;
    for(i=1;i<=k;i++)
    {
        mc=0;fst=0;sum=0;
        scanf("%lld",&b);
        for(j=1;j<=n;j++)
        {
            while(qs[j]-qs[fst]>b)
                fst++;
            mc=max(mc,j-fst);
        }
        printf("%lld\n",mc);
    }
}
