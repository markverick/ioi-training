#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
char str[1000135];
int n;
int ms[1000135],d[1000135];
pair<int,int> ft[1000135];
void add(int idx,int val)
{
    int id=idx;
    while(idx<=n)
    {
        if(val>ft[idx].X)
        {
            ft[idx].X=val;
            ft[idx].Y=id;
        }
        idx+=idx&-idx;
    }
}
pair<int,int> Max(int idx)
{
    int mc=0,id;
    while(idx>0)
    {
        if(ft[idx].X<mc)
        {
            mc=ft[idx].X;
            id=ft[idx].Y;
        }
    }
    return make_pair(mc,id);
}
void rev(int idx)
{
    while(idx<=n)
    {
        ft[idx]=-ft[idx];
        idx+=idx&-idx;
    }
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    scanf("%s",str+1);
    for(i=1;i<=n;i++)
    {
        if(str[i]=='A')
            d[i]=-1;//str[i]=-1;
        else
            d[i]=1;//str[i]=1;
        ms[i]=max(ms[i-1]+d[i],d[i]);
    }
    for(i=1;i<=n;i++)
    {
        add(i,ms[i]);
    }
    int idx=n;
    pair<int,int> rub;
    while(true)
    {
        rub=Max(idx);
        idx=rub.Y;
        rub.X;
    }
}
