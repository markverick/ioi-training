#include<bits/stdc++.h>
using namespace std;
long long a[200135],b[200135];
vector<long long> v,w;
unordered_map<long long,long long> mp,mq;
long long ha[200135],hb[200135];
int cot=0;
map<pair<int,int>,int> hsh;
vector<pair<int,int> > p;
int main()
{
    long long n,i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&a[i],&b[i]);
        v.emplace_back(a[i]);
        w.emplace_back(b[i]);
    }
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    sort(w.begin(),w.end());
    it=unique(w.begin(),w.end());
    w.resize(distance(w.begin(),it));
    for(i=0;i<v.size();i++)
        mp[v[i]]=i;
    for(i=0;i<w.size();i++)
        mq[w[i]]=i;
    for(i=1;i<=n;i++)
    {
        hsh[make_pair(mp[a[i]],mq[b[i]])]++;
        p.emplace_back(mp[a[i]],mq[b[i]]);
        ha[mp[a[i]]]++;
        hb[mq[b[i]]]++;
    }
    sort(p.begin(),p.end());
    auto it2=unique(p.begin(),p.end());
    p.resize(distance(p.begin(),it2));
    long long sum=0;
    for(i=0;i<=n;i++)
    {
        if(ha[i]>=2)
            sum+=ha[i]*(ha[i]-1)/2;
        if(hb[i]>=2)
            sum+=hb[i]*(hb[i]-1)/2;
    }
    int tmp;
    for(i=0;i<p.size();i++)
    {
        tmp=hsh[p[i]];
        if(tmp>=2)
        {
            sum-=tmp*(tmp-1)/2;
        }
    }
    printf("%lld\n",sum);
}
