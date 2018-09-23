#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
int n,Q,x,y;
int a[100135],qs[100135],xbar;
double seg[100135];
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=a[fst];
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    seg[idx]=(seg[idx*2]*(mid-fst+1)+seg[idx*2+1]*(lst-mid))/(lst-fst+1);
}
pair<int,double> sum(int idx,int fst,int lst,int baw)
{
    int mid=(fst+lst)/2;
    if(y<fst||x>lst)
    {
        return MP(0,0);
    }
    if(fst>=x&&lst<=y)
    {
        if(seg[idx]>=baw)
        {
            return MP(0,(qs[lst]-qs[fst-1])/);
        }
        else
        {
            return lst-fst+1;
        }
    }
}
int main()
{
    int i,j,k,baw;
    scanf("%d %d",&n,&Q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    build(1,1,n);
    while(Q--)
    {
        scanf("%d %d %lf",&x,&y,&baw);
        printf("%d\n",sum(1,1,n,baw));
    }
}
