#include<bits/stdc++.h>
using namespace std;
int L,n;
vector<int> v;
vector<int> ::iterator it;
int a[100135],seg[800135],lazy[800135],x,y;
unordered_map<int,int> mp;
void shift(int idx,int fst,int lst)
{
    if(lazy[idx]==1)
    {
        lazy[idx*2]^=1;
        lazy[idx*2+1]^=1;
        seg[idx]=v[lst+1]-v[fst]-seg[idx];
        lazy[idx]=0;
    }
}
void inv(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(x>lst||L<fst)
    {
        return;
    }
    if(fst>=x&&lst<=L)
    {
        seg[idx]=v[lst+1]-v[fst]-seg[idx];
        lazy[idx*2]^=1;
        lazy[idx*2+1]^=1;
        return;
    }
    inv(idx*2,fst,mid);
    inv(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
int main()
{
    int i,j,k;
    scanf("%d %d",&L,&n);
    v.emplace_back(L);
    v.emplace_back(0);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        v.emplace_back(a[i]);
    }
    sort(v.begin(),v.end());
//    it=unique(v.begin(),v.end());
//    v.resize(distance(v.begin(),it));
    for(i=0;i<v.size();i++)
        mp[v[i]]=i;
    lazy[1]=1;
    for(i=1;i<=n;i++)
    {
        x=mp[a[i]];
        inv(1,0,v.size()-2);
        shift(1,0,v.size()-2);
        printf("%d\n",seg[1]);
    }
}
