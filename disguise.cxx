#include<bits/stdc++.h>
using namespace std;
long long a[100135];
long long ha[300135];
long long hb[300135];
long long n;
//void add(int idx,long long val)
//{
//    while(idx<=n)
//    {
//        ft[idx]+=val;
//        idx+=idx&-idx;
//    }
//}
int main()
{
    long long i,j,k,p;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]==k)
        {
            p=i;
        }
    }
    long long sum=100135;
    for(i=p+1;i<=n;i++)
    {
        if(a[i]<k)
            sum++;
        else
            sum--;
        hb[sum]++;
    }
    sum=100135;
    long long out=0;
    ha[100135]++;
    hb[100135]++;
    for(i=p-1;i>=1;i--)
    {
        if(a[i]>k)
            sum++;
        else
            sum--;
        ha[sum]++;
    }
    for(i=1;i<=201135;i++)
    {
        out+=ha[i]*hb[i];
    }
    printf("%lld",out);
}
