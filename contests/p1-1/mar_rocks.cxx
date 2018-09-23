#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int x,y;
int val,toFind,hsh[300135];
tuple<int,int,int,int> t[300135];
vector<int> v;
vector<int> ::iterator it;
unordered_map<int,int> mp;
int seg[1600135],lazy[1600135],out[100135],n;
vector<pair<pair<int,int>,int > > rock;
void shift(int idx,int fst,int lst)
{
    if(lazy[idx]!=0)
    {
        seg[idx]=lazy[idx];
        if(fst!=lst)
        {
            lazy[idx*2]=lazy[idx];
            lazy[idx*2+1]=lazy[idx];
        }
        lazy[idx]=0;
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
        seg[idx]=val;
        if(fst!=lst)
        {
            lazy[idx*2]=val;
            lazy[idx*2+1]=val;
        }
        return;
    }
    Set(idx*2,fst,mid);
    Set(idx*2+1,mid+1,lst);
    if(seg[idx*2]!=n+1&&seg[idx*2]!=0&&seg[idx*2]==seg[idx*2+1])
        seg[idx]=seg[idx*2];
    else
        seg[idx]=n+1;
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
    int n,m,i,j,k;
    int a,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        t[i]=make_tuple(c,a,b,i);
        v.emplace_back(a);
        v.emplace_back(b);
        v.emplace_back(b+1);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        rock.emplace_back(make_pair(b,a),i);
        v.emplace_back(a);
    }
    v.emplace_back(-2000000000);
    v.emplace_back(2000000000);
    sort(v.begin(),v.end());
    it=unique(v.begin(),v.end());
    v.resize(distance(v.begin(),it));
    for(i=0;i<v.size();i++)
    {
        mp[v[i]]=i;
    }
    sort(&t[1],&t[n+1]);
//    for(i=0;i<=1300000;i++)
//        lazy[i]=0;

    sort(rock.begin(),rock.end());
    j=0;
    int omelet;
    for(i=1;i<=n;i++)
    {
        tie(c,a,b,val)=t[i];
        x=mp[a];y=mp[b];
        while(j<rock.size()&&c>rock[j].X.X)
        {
            toFind=mp[rock[j].X.Y];
            omelet=Find(1,0,v.size());
            if(omelet==0||omelet==n+1)
                out[rock[j].Y]=0;
            else
                out[rock[j].Y]=omelet;
            j++;
        }
        Set(1,0,v.size());
    }
    while(j<rock.size())
    {
//        printf("%d\n",j);
        toFind=mp[rock[j].X.Y];
        omelet=Find(1,0,v.size());
        if(omelet==0||omelet==n+1)
            out[rock[j].Y]=0;
        else
            out[rock[j].Y]=omelet;
        j++;
    }
    for(i=1;i<=m;i++)
    {
        printf("%d\n",out[i]);
    }
}

