#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
pair<long long,long long> p[100135];
unordered_map<long long,long long> ft;
long long hi=0;
void add(long long idx,long long val)
{
    while(idx<=hi+5)
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
    long long T,a,b,i,j,k,n;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        ft.clear();
//        memset(ft,0,sizeof ft);
        hi=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld %lld",&a,&b);
            p[i].X=a+b+11000005;
            p[i].Y=a-b+11000005;
            hi=max(hi,a+b+11000005);
        }
        sort(&p[1],&p[n+1]);
        long long sm=0,tmp;
        for(i=1;i<=n;i++)
        {
            j=i;
            while(p[j].X==p[j+1].X)
            {
                sm+=sum(p[j].Y);
                j++;
            }
            sm+=sum(p[j].Y);
            for(k=i;k<j;k++)
            {
                add(p[k].Y+1,1);
                add(p[k].X,-1);
            }
            i=j;
            add(p[i].Y+1,1);
            add(p[i].X,-1);
        }
        printf("%lld\n",sm);
    }
}
