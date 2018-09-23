#include<bits/stdc++.h>
using namespace std;
long long fac[135];
int main()
{
    int T,i,j,k,n;
    scanf("%d",&T);
    fac[1]=1;
    fac[2]=2;
    while(T--)
    {
        scanf("%d",&n);
        for(i=3;i<=n;i++)
        {
            fac[i]=fac[i-1]*i;
        }
        printf("%lld\n",fac[n]);
    }
}
