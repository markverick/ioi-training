#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[800002];
int toAdd,val;
int x,y;
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    st[idx]+=val;
    //printf("%d\n",idx);
    if(fst>=lst)
        return;
    if(toAdd<=mid)
    {
        add(idx*2,fst,mid);
    }
    else
    {
        add(idx*2+1,mid+1,lst);
    }
    return;
}
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(x>lst||y<fst)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return st[idx];
    }
    return sum(idx*2,fst,mid)+sum(idx*2+1,mid+1,lst);
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        if(a==1)
        {
            scanf("%d %d",&val,&toAdd);
            add(1,1,n);
        }
        else
        {
            scanf("%d %d",&x,&y);
            printf("%d\n",sum(1,1,n));
        }
    }
}
