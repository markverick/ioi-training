#include<bits/stdc++.h>
using namespace std;
long long x,y,val,ch[100135];
long long a[100135],b[100135],c[100135];
vector<long long> v;
vector<long long> ::iterator it;
long long seg[1350135],lazy[1350135];
void shift(long long idx,long long fst,long long lst)
{
    if(lazy[idx]!=-12345678987654321)
    {
        seg[idx]=lazy[idx]*(v[lst+1]-v[fst]);
        if(fst!=lst)
        {
            lazy[idx*2]=lazy[idx];
            lazy[idx*2+1]=lazy[idx];
        }
        lazy[idx]=-12345678987654321;
    }
}
void add(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(v[lst+1]-1<x||v[fst]>y)
    {
        return;
    }
    if(v[fst]>=x&&v[lst+1]-1<=y)
    {
        seg[idx]=(v[lst+1]-v[fst])*val;
        if(fst!=lst)
        {
            lazy[idx*2]=val;
            lazy[idx*2+1]=val;
        }
        return;
    }
    add(idx*2,fst,mid);
    add(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
long long sum(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(v[lst+1]-1<x||v[fst]>y)
    {
        return 0;
    }
    if(v[fst]>=x&&v[lst+1]-1<=y)
    {
        return seg[idx];
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
    long long n,m,i,j,k;
    scanf("%lld %lld",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%lld",&ch[i]);
        if(ch[i]==0)
        {
            scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
            a[i]++;
            v.emplace_back(a[i]);
//            v.emplace_back(a[i]+1);
            v.emplace_back(b[i]);
            v.emplace_back(b[i]+1);
        }
        else
        {
            scanf("%lld %lld",&a[i],&b[i]);
            a[i]++;
            v.emplace_back(a[i]);
//            v.emplace_back(a[i]+1);
            v.emplace_back(b[i]);            v.emplace_back(b[i]+1);
        }
    }
    v.emplace_back(-1000000000000000000);
    v.emplace_back(1000000000000000000);
    sort(v.begin(),v.end());
    it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(i=0;i<=1300000;i++)
        lazy[i]=-12345678987654321;
    for(i=1;i<=m;i++)
    {
        if(ch[i]==0)
        {
            x=a[i];y=b[i];
//            x=lower_bound(v.begin(),v.end(),a[i])-v.begin();
//            y=lower_bound(v.begin(),v.end(),b[i])-v.begin();
            val=c[i];
            add(1,0,v.size()-2);
        }
        else
        {
            x=a[i];y=b[i];
//            x=lower_bound(v.begin(),v.end(),a[i])-v.begin();
//            y=lower_bound(v.begin(),v.end(),b[i])-v.begin();
            printf("%lld\n",sum(1,0,v.size()-2));
        }
    }
}
