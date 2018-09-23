#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
long long a[100135],n,m,d;
pair<pair<long long,long long>,long long >b[100135];
// R L
vector<long long> v[100135];
long long c[100135];
long long pnt[100135];
long long ft[100135];
void add(long long idx,long long val)
{
    while(idx<=n)
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
    long long i,j;
    scanf("%lld %lld %lld",&n,&m,&d);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        pnt[a[i]]=i;
        for(j=max(a[i]-d,(long long)1);j<=min(a[i]+d,n);j++)
        {
            if(pnt[j]>0)
            {
                v[i].emplace_back(pnt[j]);
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%lld %lld",&b[i].X.Y,&b[i].X.X);
        b[i].Y=i;
    }
    sort(&b[1],&b[m]);
//    for(i=1;i<=n;i++)
//    {
//        for(j=0;j<v[i].size();j++)
//        {
//            printf("%lld ",v[i][j]);
//        }
//        printf("\n");
//    }
    long long k=1;
    for(i=1;i<=m;i++)
    {
        while(k<=b[i].X.X)
        {
            for(j=0;j<v[k].size();j++)
            {
                add(v[k][j],1);
//                printf("=%lld\n",sum(v[k][j]));
            }
            k++;
        }
        c[b[i].Y]=sum(b[i].X.X)-sum(b[i].X.Y-1);
    }
    for(i=1;i<=m;i++)
    {
        printf("%lld\n",c[i]);
    }
}
