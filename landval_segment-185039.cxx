#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[400002];//524288
int toFind,val;
int x,y;
int find_(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    //printf("%d\n",idx);
    if(fst==lst)
        return st[idx];
    if(toFind<=mid)
    {
        return find_(idx*2,fst,mid)+st[idx];
    }
    else
    {
        return find_(idx*2+1,mid+1,lst)+st[idx];
    }


}
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(x>lst||y<fst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        st[idx]+=val;
        return;
    }
    //if(fst==lst)
      //  return;
    add(idx*2,fst,mid);
    add(idx*2+1,mid+1,lst);
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
            scanf("%d %d %d",&x,&y,&val);
            add(1,1,n);
        }
        else
        {
            scanf("%d",&toFind);
           // x=toFind;y=toFind;
           //
           find_(1,1,n);
            printf("%d\n",find_(1,1,n));
        }
    }
}
