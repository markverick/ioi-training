#include<bits/stdc++.h>
#define MI 100000000000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
long long a[500135],qs[500135],bd,ft[1000135];
unordered_map<long long,long long> mp;
vector<long long> v;
void app(long long idx,long long val)
{
    while(idx<=bd)
    {
        ft[idx]=min(ft[idx],val);
        idx+=idx&-idx;
    }
}
long long Min(long long idx)
{
    long long mn=MI;
    while(idx>0)
    {
        mn=min(mn,ft[idx]);
        idx-=idx&-idx;
    }
    return mn;
}
int main()
{
//	freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	long long T,n,m,mn=MI,i,sum=0;
	scanf("%lld",&T);
	while(T--)
    {
        sum=0;
        mp.clear();
        v.clear();
        scanf("%lld %lld",&n,&m);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            qs[i]=qs[i-1]+a[i];
            v.emplace_back(m+sum);
            v.emplace_back(qs[i]);
            sum+=a[i];
        }
        sort(v.begin(),v.end());
        auto it=unique(v.begin(),v.end());
        v.resize(it-v.begin());
        for(i=0;i<v.size();i++)
            mp[v[i]]=v.size()-i;
        bd=v.size()+2;
        for(i=0;i<=bd;i++)
            ft[i]=MI;
        mn=MI;
        for(i=n;i>=1;i--)
        {
            app(mp[qs[i]],i);
            sum-=a[i];
            mn=min(mn,Min(mp[m+sum])-i+1);
//            printf("%lld -> %lld\n",i,Min(mp[m+sum]));
        }
        if(mn>=MI/10)
            printf("-1\n");
        else
            printf("%lld\n",mn);
    }
}
