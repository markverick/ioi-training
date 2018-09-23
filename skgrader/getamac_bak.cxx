#include<bits/stdc++.h>
using namespace std;
int n,m;
int x,y,val;
int st[400001];
int lazy[400001];
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    lazy[idx*2]+=lazy[idx];
    lazy[idx*2+1]+=lazy[idx];
    st[idx]+=lazy[idx]*(lst-fst+1);
    //st[idx]+=st[idx*2]*(mid-fst+1)+st[idx*2+1]*(lst-mid+2);
    lazy[idx]=0;
    if(y<fst||x>lst)
    {
        return;
    }

    if(fst>=x&&lst<=y)
    {
        lazy[idx]+=val;
        while(idx>=1)
        {
            st[idx/2]+=st[idx];
            idx/=2;
        }
        return;
    }

    add(idx*2,fst,mid);
    add(idx*2+1,mid+1,lst);
}
int find_(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    int b4=idx;
    lazy[idx*2]+=lazy[idx];
    lazy[idx*2+1]+=lazy[idx];
    st[idx]+=(lst-fst+1)*lazy[idx];
    lazy[idx]=0;

    if(y<fst||x>lst)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return st[idx]+(lst-fst+1)*lazy[idx];
    }

    return find_(idx*2,fst,mid)+find_(idx*2+1,mid+1,lst);

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
            scanf("%d %d",&x,&y);
            printf("%d\n",find_(1,1,n));
        }
    }
}
