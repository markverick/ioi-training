#include<bits/stdc++.h>
using namespace std;
int n;
char ch[100135][3];
int lazy[800135],seg[800135],x,y,val,Hi[800135],a[100135],b[100135],c[100135],k[100135],toFind;
vector<int> v;
unordered_map<int,int> mp;
void shift(int idx,int fst,int lst)
{
    if(lazy[idx]!=-2000000005)
    {
        seg[idx]=lazy[idx]*(v[lst]-v[fst]+1);
        Hi[idx]=max(0,seg[idx]);
        if(fst!=lst)
        {
            lazy[idx*2]=lazy[idx];
            lazy[idx*2+1]=lazy[idx];
        }
        lazy[idx]=-2000000005;
    }
}
void Set(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(lst<x||fst>y)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        seg[idx]=val*(v[lst]-v[fst]+1);
        Hi[idx]=max(0,seg[idx]);
        if(fst!=lst)
        {
            lazy[idx*2]=val;
            lazy[idx*2+1]=val;
        }
        return;
    }
    Set(idx*2,fst,mid);
    Set(idx*2+1,mid+1,lst);
    seg[idx]=seg[idx*2]+seg[idx*2+1];
    Hi[idx]=max(seg[idx*2]+Hi[idx*2+1],Hi[idx*2]);
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(fst==lst)
    {
        return seg[idx];
    }
    if(y<fst)
    {
        return 0;
    }
    if(y>lst)
    {
        return Hi[idx];
    }
    if(y>mid)
    {
        shift(idx*2,fst,mid);
        return max(sum(idx*2,fst,mid),seg[idx*2]+sum(idx*2+1,mid+1,lst));
    }
    if(y<=mid)
    {
        return sum(idx*2,fst,mid);
    }
}
int Sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(fst==lst)
    {
        return seg[idx];
    }
    if(fst>y)
    {
        return 0;
    }
    if(lst<=y)
    {
        return seg[idx];
    }
    return Sum(idx*2,fst,mid)+Sum(idx*2+1,mid+1,lst);
}
int Find(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    shift(idx,fst,lst);
    if(fst==lst)
    {
        return seg[idx];
    }
    if(toFind<=mid)
    {
        return Find(idx*2,fst,mid);
    }
    else
    {
        return Find(idx*2+1,mid+1,lst);
    }
}
int main()
{
    int i,j,fst,mid,lst,mc,Q,slope,height;
    for(i=0;i<=800005;i++)
        lazy[i]=-2000000005;
    scanf("%d",&n);
    v.emplace_back(0);
    v.emplace_back(2000000000);
    for(i=1;true;i++)
    {
        scanf("%s",ch[i]);
        if(ch[i][0]=='E')
        {
            Q=i-1;
            break;
        }
        if(ch[i][0]=='I')
        {
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
            v.emplace_back(a[i]);
            v.emplace_back(b[i]);
            v.emplace_back(b[i]+1);
        }
        else
        {
            scanf("%d",&k[i]);
//            v.emplace_back(k[i]);
        }
    }
    sort(v.begin(),v.end());
    auto it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(i=0;i<v.size();i++)
        mp[v[i]]=i;
    for(i=1;i<=Q;i++)
    {
        if(ch[i][0]=='I')
        {
            x=mp[a[i]];y=mp[b[i]];val=c[i];
            Set(1,0,v.size()-1);
        }
        else
        {
            fst=0;lst=v.size()-1;mc=0;
            while(fst<=lst)
            {
                mid=(fst+lst)/2;
                y=mid;
//                printf("%d <- %d -> %d\n",fst,mid,lst);
//                printf("%d <- %d -> %d\n",v[fst],v[mid],v[lst]);
                if(sum(1,0,v.size()-1)<=k[i])
                {
                    mc=max(mc,mid);
                    fst=mid+1;
                }
                else
                {
                    lst=mid-1;
                }
//                printf("%d\n",sum(1,0,v.size()-1));
            }
            if(v[mc]>=n)
            {
//                printf("%d %d %d\n",mc,v[mc],n);
            }
            else
            {
                toFind=mc;
                y=mc;
                slope=Find(1,0,v.size()-1);
                height=Sum(1,0,v.size()-1);
                y=k[i]-height;
//                printf("%d %d %d\n",mc,v[mc],slope);
                if(slope==0)
                    printf("%d\n",v[mc+1]-1);
                else
                    printf("%d\n",v[mc]+y/slope);
            }
        }
    }
    for(i=0;i<v.size();i++)
    {
        printf("%d %d\n",i,v[i]);
        y=i;
        printf("%d\n",sum(1,0,v.size()-1));
    }
}
