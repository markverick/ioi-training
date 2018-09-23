#include<bits/stdc++.h>
using namespace std;

int seg[5000000];
int teema[100135];
int peated[100135];
int hsh[200135];
int in[100135];
int mc=0;
int val,toAdd,x,y;
void add(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst==lst)
    {
        seg[idx]=val;
        return;
    }
    if(toAdd<=mid)
        add(idx*2,fst,mid);
    else
        add(idx*2+1,mid+1,lst);
    seg[idx]=max(seg[idx*2],seg[idx*2+1]);
}
int Max(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(y<fst||x>lst)
    {
        return 0;
    }
    if(x<=fst&&y>=lst)
    {
        return seg[idx];
    }
    return max(Max(idx*2,fst,mid),Max(idx*2+1,mid+1,lst));
}
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&in[i]);
        in[i]+=100001;
        hsh[in[i]]++;
    }
    int idx=1;
    for(i=1;i<=n;i++)
        peated[i]=hsh[in[i]];
    for(i=1;i<=n;i++)
    {
        toAdd=i;
        val=peated[i];
        //printf("%d ",peated[i]);
        add(1,1,n);
    }
    //printf("\n");
    teema[1]=1;
    for(i=2;i<=n;i++)
    {
        if(in[i]==in[i-1])
        {
            teema[i]=teema[i-1];
        }
        else
        {
            teema[i]=i;
        }
    }
    /*for(i=1;i<=n;i++)
    {
        printf("%d ",teema[i]);
    }*/
    for(i=1;i<=m;i++)
    {
        mc=0;
        scanf("%d %d",&x,&y);
        if(teema[x]==teema[y])
        {
            printf("%d\n",y-x+1);
            continue;
        }
        mc=max(mc,peated[x]-(x-teema[x]));
        mc=max(mc,y-teema[y]+1);
        x=teema[x]+peated[x];
        y=teema[y]-1;
        if(x<y)
            mc=max(mc,Max(1,1,n));
        if(teema[x]==teema[y])
        {
            printf("%d\n",max(mc,y-x+1));
            continue;
        }

        printf("%d\n",mc);
    }
}
