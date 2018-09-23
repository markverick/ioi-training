#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template<typename T>
using o_set=tree<T,null_type,less_equal <T>,rb_tree_tag,tree_order_statistics_node_update>;
o_set<int> seg[400135];
int toAdd,val,x,y,a,b;
int cap;
int jum,tmp;
int in[120000];
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        jum=*(seg[idx].begin());
        seg[idx].erase(seg[idx].begin());
        seg[idx].insert(val);
        return;
    }
    if(toAdd<=mid)
        add(idx*2,fst,mid);
    else
        add(idx*2+1,mid+1,lst);
    seg[idx].erase(seg[idx].find_by_order(seg[idx].order_of_key(jum)));
    seg[idx].insert(val);
}
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx].insert(in[fst]);
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    for(auto it=seg[idx*2].begin();it!=seg[idx*2].end();it++)
    {
        seg[idx].insert(*it);
    }
    for(auto it=seg[idx*2+1].begin();it!=seg[idx*2+1].end();it++)
    {
        seg[idx].insert(*it);
    }
    //seg[idx].insert(seg[idx*2].begin(),seg[idx*2].end());
    //seg[idx].insert(seg[idx*2+1].begin(),seg[idx*2+1].end());
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(y<fst||x>lst)
    {
        return 0;
    }
    if(x<=fst&&y>=lst)
    {
        int ed=seg[idx].order_of_key(b+1);
        int st=seg[idx].order_of_key(a);
            return ed-st    ;
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
char ch[3];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&in[i]);
    }
    build(1,1,n);
    for(i=1;i<=m;i++)
    {
        scanf("%s",ch);
        if(ch[0]=='c')
        {
            scanf("%d %d",&toAdd,&val);
            add(1,1,n);
        }
        else
        {
            scanf("%d %d %d %d",&x,&y,&a,&b);
            tmp=sum(1,1,n);
            //if(tmp!=1000000001)
                printf("%d\n",tmp);
           // else
             //   printf("no\n");
        }
    }
}
