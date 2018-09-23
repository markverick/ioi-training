#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
int n,k,m,val,toSet,x,y;
pair<int,int> maxt[500135];
pair<int,int> mint[500135];
int a[100135];
int i;
pair<int,int> Min[15];
pair<int,int> Max[15];
void SetX(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst>=lst)
    {
        maxt[idx]=MP(val,fst);
        return;
    }
    if(toSet<=mid)
        SetX(idx*2,fst,mid);
    else
        SetX(idx*2+1,mid+1,lst);
    if(maxt[idx*2].X>=maxt[idx*2+1].X)
        maxt[idx]=maxt[idx*2];
    else
        maxt[idx]=maxt[idx*2+1];
    return;
}
pair<int,int> findMax(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(x>lst||y<fst)
    {
        return MP(-1,maxt[idx].Y);
    }
    if(fst>=x&&lst<=y)
    {
        return maxt[idx];
    }
    pair<int,int> t1=findMax(idx*2,fst,mid);
    pair<int,int> t2=findMax(idx*2+1,mid+1,lst);
    if(t1.X>=t2.X)
    {
        return t1;
    }
    else
    {
        return t2;
    }
}
void SetY(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(fst>=lst)
    {
        mint[idx]=MP(val,fst);
        return;
    }
    if(toSet<=mid)
        SetY(idx*2,fst,mid);
    else
        SetY(idx*2+1,mid+1,lst);
    if(mint[idx*2].X<=mint[idx*2+1].X)
        mint[idx]=mint[idx*2];
    else
        mint[idx]=mint[idx*2+1];
    return;
}
pair<int,int> findMin(int idx,int fst,int lst)
{
    int mid=(fst+lst)/2;
    if(x>lst||y<fst)
    {
        return MP(1000000000,mint[idx].Y);
    }
    if(fst>=x&&lst<=y)
    {
        return mint[idx];
    }
    pair<int,int> t1=findMin(idx*2,fst,mid);
    pair<int,int> t2=findMin(idx*2+1,mid+1,lst);
    if(t1.X<=t2.X)
    {
        return t1;
    }
    else
    {
        return t2;
    }
}

int main()
{
    int j;
    scanf("%d %d %d",&n,&k,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        toSet=i;
        val=a[i];
        SetX(1,1,n);
        SetY(1,1,n);
    }
    for(j=1;j<=m;j++)
    {
        scanf("%d %d",&x,&y);
        if(y-x<=k)
        {
            printf("0\n");
            continue;
        }
        for(i=1;i<=k+1;i++)
        {
            pair<int,int> tmp=findMax(1,1,n);
            Max[i]=tmp;
            val=-1;
            toSet=tmp.Y;
            SetX(1,1,n);
        }
        /*for(i=1;i<=k;i++)
        {
            printf("%d %d, ",Max[i].X,Max[i].Y);
        }*/
        for(i=1;i<=k+1;i++)
        {
            val=Max[i].X;
            toSet=Max[i].Y;
            SetX(1,1,n);
        }
        for(i=1;i<=k+1;i++)
        {
            pair<int,int> tmp=findMin(1,1,n);
            Min[i]=tmp;
            val=1000000000;
            toSet=tmp.Y;
            SetY(1,1,n);
        }/*
        printf("Min = ");
        for(i=1;i<=k+1;i++)
        {
            printf("%d ",Min[i].X,Min[i].Y);
        }
        printf("\n");*/
        for(i=1;i<=k+1;i++)
        {
            val=Min[i].X;
            toSet=Min[i].Y;
            SetY(1,1,n);
        }
        int mn=1000000000;
        for(i=1;i<=k+1;i++)
        {
            if(Max[i].X==-1||Min[k-i+2].X==1000000000)
                continue;
            //printf("%d %d,",Max[i].X,Min[k-i+2].X);
            mn=min(mn,Max[i].X-Min[k-i+2].X);
        }
        if(mn==1000000000)
            printf("0\n");
        else
            printf("%d\n",max(0,mn));
    }
}
