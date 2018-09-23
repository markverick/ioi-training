#include<bits/stdc++.h>
using namespace std;
unordered_map<int,long long> ft;
int a[100135],n;
void add(long long idx,long long val)
{
    while(idx<=2000000005)
    {
        ft[idx]+=val;
        idx+=idx&-idx;
    }
}
long long sum(long long idx)
{
    long long sm=0;
    while(idx>0)
    {
        sm+=ft[idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    long long i,sm=0;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        a[i]++;
    }
    for(i=n;i>=1;i--)
    {
        sm+=sum(a[i]-1);
        add(a[i],1);
    }
    printf("%lld",sm);
}
