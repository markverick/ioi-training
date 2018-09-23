#include<bits/stdc++.h>
using namespace std;
char op[12];
int ft[1135];
void add(int idx,int val)
{
    while(idx<=1000)
    {
        ft[idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx)
{
    if(idx==0)
        return 0;
    int sm=0;
    while(idx>0)
    {
        sm+=ft[idx];
        idx-=idx&-idx;
    }
    return sm;
}
int main()
{
    int n,m,i,j,k,a;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%s",op);
        if(op[2]=='I')
        {
            scanf("%d",&a);
            if(sum(a)-sum(a-1)==1)
                add(a,-1);
            else
                add(a,1);
        }
        else
        {
            memset(ft,0,sizeof ft);
        }
        printf("%d\n",sum(n));
    }
}
