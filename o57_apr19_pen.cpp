#include<bits/stdc++.h>
using namespace std;
int n,val,x,y;
tuple<int,int,int,int> t[100135];
vector<int> v;
pair<int,int> p[100135];
int seg[2400135],lazy[2400135];
unordered_map<int,int> mp;
int go[100135],pos[100135];
void shift(int idx,int fst,int lst)
{
    if(lazy[idx]>0)
    {
        lazy[idx*2]=max(lazy[idx*2],lazy[idx]);
        lazy[idx*2+1]=max(lazy[idx*2+1],lazy[idx]);
        seg[idx]=(lst-fst+1)*lazy[idx];
        lazy[idx]=0;
    }
}
void Set(int idx,int fst,int lst)
{
//    printf("%d %d %d\n",idx,fst,lst);
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(y<fst||x>lst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        seg[idx]=(lst-fst+1)*val;
        lazy[idx*2]=max(lazy[idx*2],val);
        lazy[idx*2+1]=max(lazy[idx*2+1],val);
        return;
    }
    Set(idx*2,fst,mid);
    Set(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
}
int toSum;
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(fst==lst)
    {
        return seg[idx];
    }
    if(toSum<=mid)
    {
        return sum(idx*2,fst,mid);
    }
    else
    {
        return sum(idx*2+1,mid+1,lst);
    }
}
int jum[100135];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx<=0)
        return 0;
    return jum[idx]=dp(go[idx])+1;
}
int main()
{
    int i,j,k,a,b,c;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        b--;
        v.emplace_back(a);
        v.emplace_back(b);
        v.emplace_back(b+1);
        t[i]=tie(c,a,b,i);
    }
    v.emplace_back(0);
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(i=0;i<v.size();i++)
    {
        mp[v[i]]=i;
    }
    sort(&t[1],&t[n+1]);
    int d;
    for(i=1;i<=n;i++)
    {
        tie(c,a,b,d)=t[i];
        p[i]=make_pair(mp[a],mp[b]);
        pos[i]=d;
    }
    int fall=0;
    for(i=1;i<=n;i++)
    {
        tie(x,y)=p[i];
        toSum=x-1;
        fall=sum(1,0,v.size()-1);
        go[i]=fall;
        val=i;
        Set(1,0,v.size()-1);
    }
    memset(jum,-1,sizeof jum);
    for(i=1;i<=n;i++)
    {
        printf("%d\n",dp(pos[i]));
    }
}
