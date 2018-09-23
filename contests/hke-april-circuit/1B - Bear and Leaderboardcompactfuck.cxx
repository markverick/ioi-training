#include<bits/stdc++.h>
#define DT distance
using namespace std;
long long score[500135],fk[1000135];
multiset<long long> st;
multiset<long long> ::iterator il,jl,iu,ju;
set<long long> mp;
map<long long,long long> id;
set<long long> ::iterator it;
//unordered_map<long long,long long> mp;
long long A[500135],B[500135];
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
    for(it=mp.begin();it!=mp.end();it++)
    {
        id[*it]=DT(mp.begin(),it);
    }
    memset(score,0,sizeof score);
//    system("pause");
    for(i=1;i<=n;i++)
    {
        st.insert(0);
    }
    for(i=1;i<=q;i++)
    {
        a=A[i];b=B[i];
        il=st.lower_bound(score[a]);dil=DT(st.begin(),il);
        jl=st.lower_bound(score[a]+b);djl=DT(st.begin(),jl);
        iu=st.upper_bound(score[a]);diu=DT(st.begin(),iu);
        ju=st.upper_bound(score[a]+b);dju=DT(st.begin(),ju);
        prod-=(score[a])*(n-diu+1);
//        printf("1: %lld\n",prod);        prod+=(score[a]+b)*(n-dju+1);
//        printf("2: %lld -> %lld %lld\n",prod,score[a]+b,n-dju+1);
        prod+=(sumk(id[score[a]+b]-1)-score[a]-sumk(id[score[a]]-1));
//        printf("3: %lld -> %lld - %lld\n",prod,,);
        printf("%lld\n",prod);
//        system("pause");
        st.erase(il);
        st.insert(score[a]+b);
        addk(id[score[a]],-score[a]);
        addk(id[score[a]+b],score[a]+b);
        score[a]+=b;
    }
}
