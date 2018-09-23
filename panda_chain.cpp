#include<bits/stdc++.h>
using namespace std;
long long fac[1200000];
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n,k,i,j,T;
    scanf("%d",&T);
    long long hi=1;
    while(T--)
    {
        scanf("%lld %lld",&n,&k);
        if(n>1000005)
        {
            printf("0\n");
            continue;
        }
        fac[0]=1;
        if(n>=hi)
        for(i=hi;i<=n;i++)
        {
            fac[i]=fac[i-1]*i%1000003;
        }
        hi=max(hi,n);
        printf("%lld\n",k*fac[n]%1000003);
    }

}
