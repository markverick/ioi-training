#include<bits/stdc++.h>
using namespace std;
long long score[500135],ft[1000135],fk[1000135];
void add(long long idx,long long val)
{
    while(idx<=1000005)
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
void addk(long long idx,long long val)
{
    while(idx<=1000005)
    {
        fk[idx]+=val;
        idx+=idx&-idx;
    }
}
long long sumk(long long idx)
{
    long long sm=0;
    while(idx>0)
    {
        sm+=fk[idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    long long n,q,i,j,k,a,b,prod=0;
    scanf("%lld %lld",&n,&q);
    for(i=1;i<=n;i++)
    {
        score[i]=1;
    }
//    add(1,0);
    add(1,n);
    while(q--)
    {
        scanf("%lld %lld",&a,&b);
        prod-=(score[a]-1)*(n-sum(score[a])+1);
//        printf("1: %lld\n",prod);
        prod+=(score[a]+b-1)*(n-(sum(score[a]+b))+1);
//        printf("2: %lld -> %lld %lld\n",prod,score[a]+b-1,n-sum(score[a]+b)+1);
        prod+=(sumk(score[a]+b-1+1)-score[a]+1-sumk(score[a]-1+1));
//        printf("3: %lld -> %lld - %lld\n",prod,sumk(score[a]+b-2),sumk(score[a]-1));
        printf("%lld\n",prod);
        add(score[a],-1);
        add(score[a]+b,1);
//        system("pause");
        addk(score[a]+1,-score[a]+1);
        addk(score[a]+b+1,score[a]+b-1);
        score[a]+=b;
    }
}
