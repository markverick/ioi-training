#include<bits/stdc++.h>
using namespace std;
long long a[135];
int main()
{
    long long T,n,i,j,k,prod=1;
    scanf("%lld",&T);
    while(T--)
    {
        prod=1;
        scanf("%lld",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            a[i]%=1000000007;
            prod*=a[i];
            prod%=1000000007;
        }
        printf("%lld\n",prod);
    }
}
