#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[5135],b[5135];
pair<int,int> v[5135];
pair<int,int> jum[5135];
int m;
pair<int,int> dp(int idx)
{
    if(jum[idx].X>-2)
    {
        return jum[idx];
    }
    int i;
    if(idx==m)
    {
        return make_pair(0,b[idx]);
    }
    int mc=-1,dmc=-1;
    pair<int,int> p;
    for(i=idx+1;i<=m;i++)
    {
        if(a[i]>b[idx])
            break;
        if(a[idx]==a[i])
            continue;
        p=dp(i);
        if(mc<p.X)
        {
            mc=p.X;
            dmc=p.Y;
        }
        else if(mc==p.X)
        {
            dmc=max(dmc,p.Y);
        }
    }
    return jum[idx]=make_pair(mc+1,dmc);
}
int main()
{
    int i,j,k,n;
    scanf("%d %d",&n,&m);
    for(i=0;i<=m;i++)
    {
        jum[i]=make_pair(-1000000000,-1000000000);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&v[i].X,&v[i].Y);
    }
    sort(&v[1],&v[m+1]);
    for(i=1;i<=m;i++)
    {
        tie(a[i],b[i])=v[i];
    }
    a[0]=0;
    b[0]=1;
    pair<int,int> p=dp(0);
    printf("%d %d",p.X,p.Y);
}
