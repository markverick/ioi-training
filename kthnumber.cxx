#include<bits/stdc++.h>
using namespace std;
int n,Q,a[100135],b[100135],R[2000000],L[2000000],len=1,seg[2000000],head[100135],id[100135],toSet,node;
vector<int> v[100135];
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=1;
        return;
    }
    L[idx]=++len;
    build(L[idx],fst,mid);
    R[idx]=++len;
    build(R[idx],mid+1,lst);
    seg[idx]=seg[L[idx]]+seg[R[idx]];
    return;
}
void update(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        node=++len;
        seg[node]=0;
        return;
    }
    if(toSet<=mid)
    {
        update(L[idx],fst,mid);
        L[++len]=node;
        R[len]=R[idx];
        node=len;
    }
    else
    {
        update(R[idx],mid+1,lst);
        R[++len]=node;
        L[len]=L[idx];
        node=len;
    }
    seg[len]=seg[L[len]]+seg[R[len]];
}
int x=1,y;
int sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(y<fst||x>lst)
    {
        return 0;
    }
    if(fst>=x&&lst<=y)
    {
        return seg[idx];
    }
    return sum(L[idx],fst,mid)+sum(R[idx],mid+1,lst);
}
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int i,j,k,mc=0;
    scanf("%d %d",&n,&Q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        mc=max(mc,a[i]);
        v[a[i]].emplace_back(i);
    }
    build(1,1,n);
    head[0]=1;
    id[0]=1;
    k=1;
    for(i=1;i<=mc;i++)
    {
//        printf("%d\n",k);
        for(j=0;j<v[i].size();j++)
        {
            toSet=v[i][j];
            update(head[k-1],1,n);
//            printf("%d %d\n",k+1,node);
            head[k++]=node;
        }
        id[i]=head[k-1];
//        printf("=%d\n",id[i]);
    }
    int fst,mid,lst,tmp,out=-1,l;
//    system("pause");
    while(Q--)
    {
        scanf("%d %d",&l,&k);
        fst=0;lst=n;out=0;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
            y=mid;
            tmp=sum(id[l-1],1,n);
            if(tmp==k)
            {
                out=mid;
                break;
            }
            else if(tmp<k)
            {
                fst=mid+1;
            }
            else
            {
                lst=mid-1;
            }
        }
        printf("%d\n",a[out]);
    }
}
