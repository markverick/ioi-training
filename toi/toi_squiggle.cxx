#include<bits/stdc++.h>
using namespace std;
long long a[1000135],b[1000135];
int main()
{
    long long n,i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    long long sa=0,sb=0;
    for(i=1;i<n;i++)
    {
        if(i%2==1&&a[i]>=a[i+1])
        {
            sa+=a[i]+1-a[i+1];
            a[i+1]=a[i]+1;
        }
        if(i%2==0&&a[i]<=a[i+1])
        {
            sa+=a[i+1]+1-a[i];
            a[i]=a[i+1]+1;
        }
    }
    for(i=1;i<n;i++)
    {
        if(i%2==0&&b[i]>=b[i+1])
        {
            sb+=b[i]+1-b[i+1];
            b[i+1]=b[i]+1;
        }
        if(i%2==1&&b[i]<=b[i+1])
        {
            sb+=b[i+1]+1-b[i];
            b[i]=b[i+1]+1;
        }
    }
    printf("%lld",min(sa,sb));
}
