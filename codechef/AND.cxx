#include<bits/stdc++.h>
using namespace std;
long long bit[100135][35];
long long hsh[35];
int main()
{
    long long i,j,k,n,a;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a);
        j=0;
        while(a>0)
        {
            bit[i][j]=a%2;
            if(a%2)hsh[j]++;
            j++;
            a/=2;
        }
    }
    long long sum=0;
    k=0;
    for(i=1;i<=n;i++)
    {
        for(j=0,k=1;j<=32;j++,k*=2)
        {
            if(bit[i][j]==1)
            {
                hsh[j]--;
                sum+=k*hsh[j];
            }
        }
    }
    printf("%lld",sum);
}
