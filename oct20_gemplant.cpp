#include<bits/stdc++.h>
using namespace std;
int n,m;
int ft[200135];
void add(int idx,int val)
{
    while(idx<=n)
    {
        ft[idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx)
{
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
    int i,j,k,a,b,c;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        if(a==1)
        {
            add(c,b);
        }
        else
        {
            printf("%d\n",sum(c)-sum(b-1));
        }
    }
}
