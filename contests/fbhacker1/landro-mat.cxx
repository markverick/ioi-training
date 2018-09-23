#include<bits/stdc++.h>
#define X first
#define Y second
#define MI 1000000000000000000
using namespace std;
long long a[100135];
multiset<long long> st;
multiset<long long> ::iterator it;
priority_queue<pair<long long,long long> > pq;
vector<long long> v;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long T,t,i,j,k,n,m,L,d,mc,tmp;
    scanf("%lld",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%lld %lld %lld %lld",&L,&n,&m,&d);
        while(!pq.empty())pq.pop();
        v.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            pq.emplace(-a[i],i);
        }
        while(v.size()<L)
        {
            v.emplace_back(-pq.top().X);
            pq.emplace(pq.top().X-a[pq.top().Y],pq.top().Y);
            pq.pop();
        }
        sort(v.begin(),v.end());
        st.clear();
        for(i=1;i<=m;i++)
        {
            st.insert(0);
        }
        for(i=0;i<v.size();i++)
        {
            tmp=max(*(st.begin()),v[i])+d;
            st.erase(st.begin());
            st.insert(tmp);
        }
        mc=0;
        for(it=st.begin();it!=st.end();it++)
        {
            mc=max(mc,*it);
        }
        printf("Case #%lld: %lld\n",t,mc);
    }
}
