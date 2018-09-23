#include<bits/stdc++.h>
#define X first
#define Y second
#define MAX_INT -1000000000000000000
using namespace std;
long long a[100135],b[100135],c[100135],d[100135],n,qs[100135],qr[100135],x,y;;
pair<long long,long long> ser[400135],seg[400135];
void build(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(fst==lst)
    {
        ser[idx]={qr[fst],fst};
        seg[idx]={qs[fst],fst};
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    if(seg[idx*2].X>=seg[idx*2+1].X)
        seg[idx]=seg[idx*2];
    else
        seg[idx]=seg[idx*2+1];
    if(ser[idx*2].X>=ser[idx*2+1].X)
        ser[idx]=ser[idx*2];
    else
        ser[idx]=ser[idx*2+1];
}
pair<long long,long long> Find(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return {MAX_INT,0};
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    pair<long long,long long> a=Find(idx*2,fst,mid),b=Find(idx*2+1,mid+1,lst);
    if(a.X>=b.X)
    {
        return a;
    }
    else
    {
        return b;
    }
}
pair<long long,long long> Finr(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return {MAX_INT,0};
    }
    if(fst>=x&&lst<=y)
    {
        return ser[idx];
    }
    pair<long long,long long> a=Finr(idx*2,fst,mid),b=Finr(idx*2+1,mid+1,lst);
    if(a.X>=b.X)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int main()
{
    printf("%d %lld",MAX_INT,MAX_INT);
    long long i,j,k,m,mc=MAX_INT,p;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&c[i],&d[i]);
    }
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&a[i],&b[i]);
        qs[i]=b[i]-a[i];
        qr[i]=b[i]+a[i];
//        qs[i]=qs[i-1]+b[i]-a[i];
    }
    build(1,1,n);
//    x=1;y=n;
//    printf("%lld\n",Find(1,1,n) );
    for(i=1;i<=n;i++)
    {
        mc=MAX_INT;
        m=lower_bound(&a[1],&a[n+1],c[i])-&a[0];
        x=m;y=n;
        if(x<=y)
        {
            p=Find(1,1,n).Y;
            mc=max(mc,b[p]+d[i]-abs(a[p]-c[i]));
        }
        x=1;y=m-1;
        if(x<=y)
        {
            p=Finr(1,1,n).Y;
            mc=max(mc,b[p]+d[i]-abs(a[p]-c[i]));
        }
        printf("%lld\n",mc);
    }
}
