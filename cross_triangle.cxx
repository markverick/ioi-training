#include<bits/stdc++.h>
using namespace std;
int a[100135],b[100135],ft[3][1000135];
void add(int idx,int axis,int val)
{
    while(idx<=1000005)
    {
        ft[axis][idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx,int axis)
{
    int sm=0;
    while(idx>0)
    {
        sm+=ft[axis][idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    int n,m,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=3;j++)
        {
            scanf("%d %d",&a[j],&b[j]);
            a[j]++;b[j]++;
        }
        sort(&a[1],&a[4]);
        sort(&b[1],&b[4]);
        add(a[1]+1,0,1);
        add(a[3],0,-1);
        add(b[1]+1,1,1);
        add(b[3],1,-1);
    }
    scanf("%d",&m);
    int c;
    char ch[4];
    for(i=1;i<=m;i++)
    {
        scanf("%s %*s %d",ch,&c);
        c++;
        if(ch[0]=='x')
        {
            printf("%d\n",sum(c,0));
        }
        else
        {
            printf("%d\n",sum(c,1));
        }
    }
}
