#include<bits/stdc++.h>
using namespace std;
int x[100135],y[100135];
vector<pair<int,int> > vx;
vector<int> vy;
int fl[1000135];
int fr[1000135];
int n;
void add(int idx,int val,char fn)
{
    while(idx<=1000000)
    {
        if(fn=='L')
            fl[idx]+=val;
        else
            fr[idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx,char fn)
{
    int sm=0;
    while(idx>0)
    {
        if(fn=='L')
            sm+=fl[idx];
        else
            sm+=fr[idx];
    }
    return sm;
}
int main()
{
    int i,j,k,fst,mid,lst;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        vx.emplace_back(x[i],y[i]);
        add(y[i],1,'R');
    }
    sort(vx.begin(),vx.end());
    for(i=0;i<vx.size();i++)
    {
        add(vx[i].Y,1,'L');
        add(vx[i].Y,-1,'R');
        fst=0;lst=n;
        while(fst<=lst)
        {
            mid=(fst+lst)/2;
        }
    }
}
