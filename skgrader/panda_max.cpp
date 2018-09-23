#include<bits/stdc++.h>
using namespace std;
long long v[120000];
int main()
{
    int n,i,j,k;
    long long a=0,b=0,c=0,d=0;
    scanf("%d",&n);
    long long temp;
    for(i=0;i<n;i++)
    {
        scanf("%lld",&v[i]);
        if(v[i]>=0&&a<v[i])
        {
            a=v[i];
            temp=i;
        }
    }
    for(i=0;i<n;i++)
    {
        if(i==temp)
            continue;
        if(v[i]>=0)
            b=max(b,v[i]);
    }
    temp=-1;
    for(i=0;i<n;i++)
    {
        if(v[i]<0&&c>v[i])
        {
            //
            c=v[i];
            //printf("===%lld\n",c);
            temp=i;
        }
    }
    if(temp>-1)
    for(i=0;i<n;i++)
    {
        if(i==temp)
            continue;
        if(v[i]<0)
            d=min(d,v[i]);
    }
    //printf("%lld %lld %lld %lld\n",a,b,c,d);
    if(temp!=-1&&c<0&&d<0)

        printf("%lld",max(a*b,c*d));
    else
        printf("%lld",a*b);
}
