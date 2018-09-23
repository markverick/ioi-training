#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
int a[100135],b[100135],seg[2000135],toAdd,n,H,L,val;
vector<int> v;
map<int,int> mp;
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]+=val;
//        printf("%d\n",seg[idx]);
        return;
    }
    if(toAdd<=mid)
    {
        add(idx*2,fst,mid);
    }
    else
    {
        add(idx*2+1,mid+1,lst);
    }
    seg[idx]=max(seg[idx*2],seg[idx*2+1]);
}
int main()
{
    int i,j,k,fst;
    scanf("%d %d %d",&n,&L,&H);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        for(j=b[i];j<=b[i]+H;j++)
            v.emplace_back(j);
    }
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(i=0;i<v.size();i++)
        mp[v[i]]=i;
    fst=1;
    int mc=0;
    for(i=1;i<=n;i++)
    {
        for(j=b[i];j<=b[i]+H;j++)
        {
            val=1;
            toAdd=mp[j];
            add(1,0,v.size()-1);
        }
        while(a[i]-a[fst]>L)
        {
            for(j=b[fst];j<=b[fst]+H;j++)
            {
                val=-1;
                toAdd=mp[j];
                add(1,0,v.size()-1);
            }
            fst++;
        }
        mc=max(mc,seg[1]);
    }
    printf("%d",mc);
}
