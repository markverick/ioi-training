#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int ft[30][100135];
int st[30]
void add(int idx,int val,int f)
{
    while(idx<=100005)
    {
        ft[f][idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx,int f)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[f][idx];
        idx-=idx&-idx;
    }
    return sm;
}
void Swap(int *p,int *q)
{
    int tmp=*p;
    *p=*q;
    *q=tmp;
}
int main()
{
    int n,m,i,j,k,x,y,x1,y1,x2,y2;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        x1++;x2++;y1++;y2++;
        if(x2<x1)
            Swap(&x1,&x2);
        if(y2<y1)
            Swap(&y1,&y2);
        if(x1<y1)
        {
            for(j=0;j<=k;j++)
            {
                add(y1,1,k+j);
            }
            for(j=1;j<=k;j++)
            {
                add(y1,1,k-j);
            }
        }
        else
        {
            for(j=0;j<=k;j++)
            {
                if(y1-j>0)
                {
                    st[k+j]=y1-j;
                    add(y1-j,1,k+j);
                }
            }
            for(j=1;j<=k;j++)
            {
                add(y1+j,1,k-j);
            }
        }
        if(x2<y2)
        {
            for(j=0;j<=k;j++)
            {
                if(y2-j+1>0)
                add(y2-j+1,-1,k+j);
            }
            for(j=1;j<=k;j++)
            {
                add(y2+j+1,-1,k-j);
            }
        }
        else
        {
            for(j=0;j<=k;j++)
            {
                add(y2+1,-1,k+j);
            }
            for(j=1;j<=k;j++)
            {
                add(y2+1,-1,k-j);
            }
        }

    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        x++;y++;
        printf("%d\n",sum(y,k+x-y));

    }
}
