#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<double,double> a[1135];
int main()
{
    long long n,d,x,y,i,T=0,fu=0;
    while(scanf("%lld %lld",&n,&d)!=EOF)
    {
        T++;fu=0;
        if(n==0&&d==0)
            return 0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&x,&y);
            if(y>d)
            {
                fu=1;
            }
            a[i].Y=x-sqrt(d*d-y*y);
            a[i].X=x+sqrt(d*d-y*y);
        }
        if(fu==1)
        {
            printf("Case %lld: -1\n",T);
            continue;
        }
        sort(&a[1],&a[n+1]);
        long long now=-1000000000,cot=0;
        for(i=1;i<=n;i++)
        {
            if(a[i].Y>now)
            {
                cot++;
                now=a[i].X;
            }
        }
        printf("Case %lld: %lld\n",T,cot);
    }
}
