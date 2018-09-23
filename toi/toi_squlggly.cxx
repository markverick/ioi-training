#include<bits/stdc++.h>
using namespace std;
int a[1000135],b[1000135];
long long dpa[1000135],dpb[1000135];
long long mn=100000000,idx;
int main()
{
    long long n,i,j,k,sum=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        b[i]=a[i];
    }
    for(i=1;i<n;i++)
    {
        if(i%2==1)
        {
            a[i]=a[i+1]-a[i];
            b[i]=b[i]-b[i+1];
        }
        else
        {
            a[i]=a[i]-a[i+1];
            b[i]=b[i+1]-b[i];
        }
    }
//        for(i=1;i<n;i++)
//        printf("%d ",a[i]);
//    printf("\n");
//    for(i=1;i<n;i++)
//        printf("%d ",b[i]);

    long long s1=0,s2=0;
    for(i=1;i<n;i++)
    {
        if(a[i]<=0)
        {
            s1+=-a[i]+1;
            a[i+1]+=-a[i]+1;a[i]=1;
        }
        if(b[i]<=0)
        {
            s2+=-b[i]+1;
            b[i+1]+=-b[i]+1;b[i]=1;
        }
    }
    printf("%lld",min(s1,s2));

}
