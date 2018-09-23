#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
pair<long long,long long> p[100135];
long long ft[100135];
unordered_map<long long,long long> mp;
void add(long long idx,long long val)
{
    while(idx<100005)
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
    long long i,j,k,n,cot=0;
    scanf("%lld",&n);
    vector<long long> v;
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&p[i].X,&p[i].Y);
        v.emplace_back(p[i].Y);
    }
    sort(&p[1],&p[n+1]);
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(i=0;i<v.size();i++)
        mp[v[i]]=i+1;
    for(i=1;i<=n;i++)
    {
        p[i].Y=mp[p[i].Y];
        cot+=i-sum(p[i].Y)-1;
        add(p[i].Y,1);
    }
    printf("%lld",cot);
}
