#include<bits/stdc++.h>
using namespace std;
multiset<int> seg[400135];
int toAdd,val,x,y;
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
    seg[idx].erase(seg[idx].find(jum));
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
    seg[idx].insert(seg[idx*2].begin(),seg[idx*2].end());
    seg[idx].insert(seg[idx*2+1].begin(),seg[idx*2+1].end());
}
int Min(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(y<fst||x>lst)
    {
        return 1000000001;
    }
    if(x<=fst&&y>=lst)
    {
        auto it=seg[idx].upper_bound(cap);
        if(it==seg[idx].end())
            return 1000000001;
        else
        return *it;
    }
    return min(Min(idx*2,fst,mid),Min(idx*2+1,mid+1,lst));
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
            scanf("%d %d %d",&x,&y,&cap);
            tmp=Min(1,1,n);
            if(tmp!=1000000001)
                printf("%d\n",tmp);
            else
                printf("no\n");
        }
    }
}
