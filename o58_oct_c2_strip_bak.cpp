#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int ft[10005][10005];
void add(int x,int y,int val)
{
    int tmp=y;
    while(x<=10000)
    {
        y=tmp;
        while(y<=10000)
        {
            ft[x][y]+=val;
            y+=y&-y;
        }
        x+=x&-x;
    }
}
void Swap(int *p,int *q)
{
    int tmp=*p;
    *p=*q;
    *q=tmp;
}

int sum(int x,int y)
{
    int sm=0,tmp=y;
    while(x>0)
    {
        y=tmp;
        while(y>0)
        {
            sm+=ft[x][y];
            y-=y&-y;
        }
        x-=x&-x;
    }
    return sm;
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
        add(x1,y1,1);
        add(x2+1,y1,-1);
        add(x1,y2+1,-1);
        add(x2+1,y2+1,1);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        x++;y++;
        printf("%d\n",sum(x,y));
    }
}
