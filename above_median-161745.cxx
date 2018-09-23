#include<bits/stdc++.h>
using namespace std;
long long a[200135];
long long qs[200135];
long long ft[200135];
long long n,x;
void add(long long idx,long long val)
{
    while(idx<=100010+n)
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
    long long i,j,k;
    scanf("%d %d",&n,&x);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>=x)
            a[i]=1;
        else
            a[i]=-1;
        qs[i]=qs[i-1]+a[i];
        //printf("F");
        add(100005+qs[i],1);
    }
    long long cot=0;
    for(i=1;i<=n;i++)
    {
        if(i>1)
            add(100005+qs[i-1],-1);
        cot+=sum(100005+n)-sum(100005+qs[i-1]-1);
    }
    printf("%lld",cot);
}
