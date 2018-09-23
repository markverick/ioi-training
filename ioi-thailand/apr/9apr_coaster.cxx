#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long x,y,val;
long long st[1000000];
long long lazy[1000000];
void add(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lazy[idx]!=100000000000000000)
    {
        st[idx]=max(st[idx],lazy[idx]);
        lazy[idx*2]=lazy[idx];
        lazy[idx*2+1]=lazy[idx];
        lazy[idx]=100000000000000000;
    }
    if(y<fst||x>lst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        lazy[idx*2]=val;
        lazy[idx*2+1]=val;
        st[idx]=max(st[idx],val);
        return;
    }
    add(idx*2,fst,mid);
    add(idx*2+1,mid+1,lst);
    st[idx]=max(st[idx*2],st[idx*2+1]);
}
long long sum(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lazy[idx]!=100000000000000000)
    {
        st[idx]=max(st[idx],lazy[idx]);
        lazy[idx*2]=lazy[idx];
        lazy[idx*2+1]=lazy[idx];
        lazy[idx]=100000000000000000;
    }
    if(y<fst||x>lst)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return st[idx]/*+lazy[idx]*(lst-fst+1)*/;
    }
    return max(sum(idx*2,fst,mid),sum(idx*2+1,mid+1,lst));
}
int main()
{
    long long i,j,k;
    scanf("%lld",&n);
    for(i=0;i<499999;i++)
    lazy[i]=100000000000000000;
    char a[3];
    while(scanf("%s",a)!=EOF)
    {
        if(a[0]=='E')
        {
            return 0;
        }
        if(a==0)
        {
            scanf("%lld %lld %lld",&x,&y,&val);
            x++;
            add(1,1,n+1);
        }
        else
        {
            scanf("%lld %lld",&x,&y);
            x++;
            printf("%lld\n",sum(1,1,n+1));
        }
    }
}
