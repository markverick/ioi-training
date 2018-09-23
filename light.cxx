#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long x,y;
long long st[800000];
long long lazy[800000];
void add(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lazy[idx]==1)
    {
        st[idx]=(lst-fst+1)-st[idx];
        lazy[idx*2]^=lazy[idx];
        lazy[idx*2+1]^=lazy[idx];
        lazy[idx]=0;
    }
    if(y<fst||x>lst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        lazy[idx*2]^=1;
        lazy[idx*2+1]^=1;
        st[idx]=(lst-fst+1)-st[idx];
        return;
    }
    add(idx*2,fst,mid);
    add(idx*2+1,mid+1,lst);
    st[idx]=st[idx*2]+st[idx*2+1];
}
long long sum(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lazy[idx]==1)
    {
        st[idx]=(lst-fst+1)-st[idx];
        lazy[idx*2]^=lazy[idx];
        lazy[idx*2+1]^=lazy[idx];
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
int main()
{
    long long i,j,k;
    scanf("%lld %lld",&n,&m);
    for(i=0;i<m;i++)
    {
        long long a;
        scanf("%lld",&a);
        if(a==0)
        {
            scanf("%lld %lld",&x,&y);
            //x++;y++;
            add(1,1,n);
        }
        else
        {
            scanf("%lld %lld",&x,&y);
            //x++;y++;
            printf("%lld\n",sum(1,1,n));
        }
    }
}
