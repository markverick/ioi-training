#include<bits/stdc++.h>
using namespace std;
int a[50135],b[50135];
vector<int> v;
unordered_map<int,int> id;
int ft[200135];
void add(int idx,int val)
{
    while(idx<=v.size())
    {
        ft[idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        v.emplace_back(a[i]+1);
        v.emplace_back(b[i]-1);
        v.emplace_back(b[i]);
    }
    v.emplace_back(-1);
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(i=1;i<v.size();i++)
    {
        id[v[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        add(id[a[i]+1],1);
        add(id[b[i]],-1);
    }
    int sm=0,st,ed;
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
//        ed=lower_bound(v.begin(),v.end(),k)-v.begin();
        st=upper_bound(v.begin(),v.end(),k)-v.begin()-1;
        sm+=sum(st);
        sm%=2007;
    }
    printf("%d",sm);
}
