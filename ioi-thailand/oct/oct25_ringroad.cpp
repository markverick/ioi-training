#include<bits/stdc++.h>
using namespace std;
long long n,k,q,toset;
long long teema[200135],d[200135],p[200135];
long long seg[800135],x,y,val;
void Set(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=val;
        return;
    }
    if(toset<=mid)
    {
        Set(idx*2,fst,mid);
    }
    else
    {
        Set(idx*2+1,mid+1,lst);
    }
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
long long sum(long long idx,long long fst,long long lst)
{
    long long mid=(fst+lst)/2;
    if(lst<x||fst>y)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
long long shortest(long long st,long long ed)
{
    long long tmp,mn=2000000135000000000;
    if(st==ed)
        return 0;
    if(st>ed)
    {
        tmp=st;st=ed;ed=tmp;
    }
    x=st;y=ed-1;
    if(x<=y)
        mn=sum(1,1,k);
    //printf("DIRECT 8=D %lld %lld -> %lld\n",mn,st,ed);
    x=ed;y=k;
    tmp=sum(1,1,k);
    x=1;y=st-1;
    if(x<=y)
        tmp+=sum(1,1,k);
    return min(mn,tmp);
}
int main()
{
    long long i,j,ch,a,b,c;
    scanf("%lld %lld %lld",&n,&k,&q);
    for(i=1;i<=k;i++)
    {
        scanf("%lld",&val);
        toset=i;
        Set(1,1,k);
        teema[i]=i;
        p[i]=i;
    }
    for(i=k+1;i<=n;i++)
    {
        scanf("%lld %lld",&a,&b);
        p[i]=a;
        d[i]=d[a]+b;
        teema[i]=teema[a];
    }
    for(i=1;i<=q;i++)
    {
        scanf("%lld",&ch);
        if(ch==0)
        {
            scanf("%lld %lld",&toset,&val);
            Set(1,1,k);
        }
        else
        {
            scanf("%lld %lld",&a,&b);
            long long aa=a,bb=b;
            if(teema[a]==teema[b])
            {
                while(135)
                {
                    if(a==b)
                    {
                        printf("%lld\n",d[aa]-d[a]+d[bb]-d[b]);break;
                    }
                    else if(a>b)
                        a=p[a];
                    else
                        b=p[b];

                }
            }
            else
                printf("%lld\n",d[a]+d[b]+shortest(teema[a],teema[b]));
        }
    }
}
