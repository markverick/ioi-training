#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int a[100135],b[100135],n;
unordered_map<int,unordered_map<int,int> >ft;
pair<int,int> c[100135],d[100135];
void add(int x,int y,int val)
{
    int tmp=y;
    while(x<=n)
    {
        y=tmp;
        while(y<=n)
        {
            ft[x][y]+=val;
            y+=y&-y;
        }
        x+=x&-x;
    }
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
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        c[i]={a[i],i};d[i]={b[i],i};
    }
    sort(&c[1],&c[n+1]);
    sort(&d[1],&d[n+1]);
    for(i=1;i<=n;i++)
    {
        a[c[i].Y]=i;
        b[d[i].Y]=i;
    }
    for(i=1;i<=n;i++)
    {
        if(i-1-sum(a[i],n)-sum(n,b[i])+sum(a[i],b[i]) )
    }
}
