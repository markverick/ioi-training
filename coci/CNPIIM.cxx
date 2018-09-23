#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long T,i,j,k,a,sq,sum=0,n;
    scanf("%lld",&T);
    while(T--)
    {
        sum=0;
        scanf("%lld",&n);
        for(i=1;i<n;i++)
        {
            a=i*(n-i);
            sq=sqrt(a-1)+0.00001;
            for(j=1;j<=sq;j++)
            {
                sum+=((a-1)/j-sq)*2;
            }
            sum+=sq*sq;
        }
        printf("%lld\n",sum);
    }
}
