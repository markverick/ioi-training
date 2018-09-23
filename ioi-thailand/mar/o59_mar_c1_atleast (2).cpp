#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
int n,Q,x,y;
int a[100135],qs[100135];
double xbar,baw;
int Min[100135],Max[100135];
void build(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        Max[idx]=a[fst];
        Min[idx]=a[fst];
        return;
    }
    build(idx*2,fst,mid);
    build(idx*2+1,mid+1,lst);
    Max[idx]=max(Max[idx*2],Max[idx*2+1]);
    Min[idx]=min(Min[idx*2],Min[idx*2+1]);
}
int cot=0,del=0;
vector<int> v;
void sum(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2,i;
    if(y<fst||x>lst)
    {
        return;
    }
    if(fst>=x&&lst<=y)
    {
        if(baw>Min[idx])
        {
            for(i=fst;i<=lst;i++)
            {
                if(a[idx]>=baw)
                    break;
                v.emplace_back(i);
            }
        }
//        else if(baw>Max[idx])
//        {
//            xbar=(xbar*cot-(qs[lst]-qs[fst-1]))/(cot-(lst-fst+1));
//            cot-=lst-fst+1;
//            printf("!%d %d\n",fst,lst);
//            del+=lst-fst+1;
//        }
//        return;
        return;
    }
    sum(idx*2,fst,mid);
    sum(idx*2+1,mid+1,lst);
    return;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&Q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    build(1,1,n);
    int item=0,Sum=0,xbar=0;
    while(Q--)
    {
        v.clear();
        scanf("%d %d %lf",&x,&y,&baw);
        xbar=(qs[y]-qs[x-1])/(y-x+1);
        Sum=qs[y]-qs[x-1];
        cot=y-x+1;
        sum(1,1,n);
//        sort(v.begin(),v.end());
        // for(i=0;i<v.size();i++)
        // {
        //     printf("!%d\n",v[i]);
        // }
        for(i=0;i<v.size();i++)
        {
            if((double)Sum/cot>=baw)
            {
                break;
            }
            Sum-=a[v[i]];
            cot--;
        }
        printf("%d\n",i);
    }
}
