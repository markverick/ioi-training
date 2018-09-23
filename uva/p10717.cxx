#include<bits/stdc++.h>
using namespace std;
long long a[70];
vector<long long> v;
int main()
{
    long long n,t,i,j,k,l,b;
    while(scanf("%lld %lld",&n,&t)!=EOF)
    {
        if(n==0&&t==0)
            return 0;
        v.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        long long gg;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                for(k=j+1;k<=n;k++)
                {
                    for(l=k+1;l<=n;l++)
                    {
                        gg=a[i]*a[j]/__gcd(a[i],a[j]);
                        gg=gg*a[k]/__gcd(gg,a[k]);
                        gg=gg*a[l]/__gcd(gg,a[l]);
                        v.emplace_back(gg);
                    }
                }
            }
        }
        long long mc,mn;
        for(i=1;i<=t;i++)
        {
            mc=0;mn=1000000000000000000;
            scanf("%lld",&b);
            for(j=0;j<v.size();j++)
            {
                mc=max(mc,v[j]*(b/v[j]));
                mn=min(mn,v[j]*( (b-1)/v[j]+1));
            }
            //printf("%lld %lld\n",, );
            printf("%lld %lld\n",mc,mn);
        }
    }
}
