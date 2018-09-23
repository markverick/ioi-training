#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define X first
#define Y second
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using o_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
int n,m;
int x,y,val;
o_set<int> st[800000];
int lazy[800000];
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        st[idx].insert(0);
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    for(auto it=st[idx*2].begin();it!=st[idx*2].end();it++)
        st[idx].insert(*it);
    for(auto it=st[idx*2+1].begin();it!=st[idx*2+1].end();it++)
        st[idx].insert(*it);
//    st[idx].insert(st[idx*2].begin(),st[idx*2].end());
//    st[idx].insert(st[idx*2+1].begin(),st[idx*2+1].end());
}
void add(int idx,int fst,int lst)
{
    long long mid=(fst+lst)/2;
    if(lazy[idx]!=0)
    {
        st[idx]+=lazy[idx]*(lst-fst+1);
        lazy[idx*2]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
        lazy[idx]=0;
    }
    if(y<fst||x>lst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        lazy[idx*2]=max(lazy[idx*2],val);
        lazy[idx*2+1]=max(lazy[idx*2+1],val);
        for(it=st[idx].begin();it!=st[idx].end();it++)
        {
            if(*it<val)
            {
                if(idx/2>0)
                {
                    st[idx/2].erase(st[idx/2].find_by_order(st[idx/2].order_of_key(*it)));
                    st[idx/2].insert(val);

                }
                it=st[idx].erase(it);
                st[idx].insert(val);
            }
        }
        return;
    }
    add(idx*2,fst,mid);
    add(idx*2+1,mid+1,lst);
    st[idx]=st[idx*2]+st[idx*2+1];
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(lazy[idx]!=0)
    {
        st[idx]+=lazy[idx]*(lst-fst+1);
        lazy[idx*2]+=lazy[idx];
        lazy[idx*2+1]+=lazy[idx];
        lazy[idx]=0;
    }
    if(y<fst||x>lst)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return st[idx]/*+lazy[idx]*(lst-fst+1)*/;
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
    int i,j,k,sm=0,T;
    scanf("%d",&T);
    while(T--)
    {
        sm=0;
        scanf("%d",&n);
        memset(st,0,sizeof st);
        memset(lazy,0,sizeof lazy);
        for(i=1;i<=n;i++)
        {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            b--;
            x=a;y=b;val=c-1;
            sm+=sum(1,1,100005);
            x=a;y=b;val=c;
            add(1,1,100005);
            printf("%d\n",sm);
        }
        printf("%d\n",sm);
    }
    scanf("%*lld");
}
