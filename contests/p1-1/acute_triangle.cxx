#include<bits/stdc++.h>
using namespace std;
long long a[40135];
long long b[40145];
int main()
{
    long long n,i,j,k,fst=0,lst=0,r,all=0,t=0,sum=0,p;
    b[3]=1;
    for(i=4;i<=40005;i++)
    {
        b[i]=b[i-1]+i-2;
    }
    while(scanf("%lld %lld",&n,&r)!=EOF)
    {
        t++;
        if(n==0&&r==0)
            return 0;
        all=n*(n-1)*(n-2)/6;
        for(i=1;i<=n;i++)
        {
            scanf("%lld.%lld",&a[i],&p);
            a[i]=a[i]*1000+p;
            a[n+i]=a[i]+360000;
        }
        sort(&a[1],&a[2*n+1]);
        fst=1;
        sum=0;
        for(lst=1;lst<=2*n;lst++)
        {
            while(a[lst]-a[fst]>180000)
            {
                fst++;
            }
            if(fst>2*n)break;
            if(lst-fst+1>=3)
            {
                sum+=b[lst-fst+1];
            }
        }
        fst=1;
        for(lst=1;lst<=n;lst++)
        {
            while(a[lst]-a[fst]>180000)
            {
                fst++;
            }
            if(fst>n)break;
            if(lst-fst+1>=3)
                sum-=b[lst-fst+1];
        }
        printf("Case %lld: %lld\n",t,all-sum);
    }
}
