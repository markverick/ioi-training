#include<bits/stdc++.h>
#define DT distance
using namespace std;
long long score[500135],fk[1000135],ft[1000135];
set<long long> mp;
map<long long,long long> id;
set<long long> ::iterator it;
//unordered_map<long long,long long> mp;
long long A[500135],B[500135];
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
    long long n,q,i,j,k,a,b,prod=0,dil,djl,diu,dju;
    scanf("%lld %lld",&n,&q);
    mp.insert(0ll);
    mp.insert(-1ll);
    for(i=1;i<=q;i++)
    {
        scanf("%lld %lld",&A[i],&B[i]);
        score[A[i]]+=B[i];
        mp.insert(score[A[i]]);
    }
    k=1;
    for(it=mp.begin();it!=mp.end();it++)
    {
        id[*it]=k++;
    }
    memset(score,0,sizeof score);
    add(id[0],n);
//    system("pause");
    for(i=1;i<=q;i++)
    {
        a=A[i];b=B[i];
        prod-=(score[a])*(n-sum(id[score[a]])+1);
//        printf("1: %lld\n",prod);        prod+=(score[a]+b)*(n-sum(id[score[a]+b])+1);
//        printf("2: %lld -> %lld %lld\n",prod,score[a]+b,n-sum(id[score[a]+b])+1);
        prod+=(sumk(id[score[a]+b]-1)-score[a]-sumk(id[score[a]]-1));
//        printf("3: %lld -> %lld - %lld\n",prod,,);
        printf("%lld\n",prod);
//        system("pause");
        add(id[score[a]],-1);
        add(id[score[a]+b],1);
        addk(id[score[a]],-score[a]);
        addk(id[score[a]+b],score[a]+b);
        score[a]+=b;
    }
}
