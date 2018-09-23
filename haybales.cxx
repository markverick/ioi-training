#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
#define MI 1000000000
using namespace std;
long long n,m;
long long x,y,val;
long long st[1700000],Min[1700000];
long long lazy[1700000],lazx[1700000],a[200135];
void build(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(fst==lst)
    {
        st[idx]=a[fst];
        Min[idx]=a[fst];
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    Min[idx]=min(Min[idx*2],Min[idx*2+1]);
    st[idx]=st[idx*2]+st[idx*2+1];
}
void add(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lazy[idx]!=0)
    {
        st[idx]+=lazy[idx]*(lst-fst+1);
        Min[idx]+=lazy[idx];
        lazy[idx*2]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
        lazy[idx]=0;
    }
    if(y<fst||x>lst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        lazy[idx*2]+=val;
        lazy[idx*2+1]+=val;
        st[idx]+=val*(lst-fst+1);
        Min[idx]+=val;
        return;
    }
    add(idx*2,fst,mid);
    add(idx*2+1,mid+1,lst);
    st[idx]=st[idx*2]+st[idx*2+1];
    Min[idx]=min(Min[idx*2],Min[idx*2+1]);
//    printf("[%lld <-> %lld] %lld %lld %lld\n",fst,lst,Min[idx],Min[idx*2],Min[idx*2+1]);
}
long long sum(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lazy[idx]!=0)
    {
        st[idx]+=lazy[idx]*(lst-fst+1);
        Min[idx]+=lazy[idx];
        lazy[idx*2]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
        lazy[idx]=0;
    }
    if(y<fst||x>lst)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return st[idx]/*+lazy[idx]*(lst-fst+1)*/;
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
long long findMin(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lazy[idx]!=0)
    {
        st[idx]+=lazy[idx]*(lst-fst+1);
        Min[idx]+=lazy[idx];
        lazy[idx*2]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
        lazy[idx]=0;
    }
    if(y<fst||x>lst)
    {
        return 1000000000000000000;
    }
    if(fst>=x&&lst<=y)
    {
        return Min[idx]/*+lazy[idx]*(lst-fst+1)*/;
    }
    return min(findMin(idx*2,fst,mid),findMin(idx*2+1,mid+1,lst));
}

int main()
{
    freopen("haybales.in","r",stdin);
    freopen("haybales.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    long long i;
    char ch[5];
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    build(1,1,n);
    for(i=1;i<=m;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='M')
        {
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",findMin(1,1,n));
        }
        else if(ch[0]=='P')
        {
            scanf("%lld %lld %lld",&x,&y,&val);
            add(1,1,n);
        }
        else
        {
            scanf("%lld %lld",&x,&y);
            printf("%lld\n",sum(1,1,n));
        }
    }
}
