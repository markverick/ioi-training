///By STAZIRAMPAGES
#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],n;
pair<int,int> ft[100135],res[100135];
pair<int,int> Max(int idx)
{
    int mc=0,x=0;
    while(idx>0)
    {
        if(mc<ft[idx].X)
        {
            mc=ft[idx].X;
            x=ft[idx].Y;
        }
        idx-=idx&-idx;
    }
    return MP(mc,x);
}
void append(int idx,int val,int mc)
{
    while(idx<=n)
    {
        if(ft[idx].X<mc)
        {
            ft[idx].X=mc;
            ft[idx].Y=val;
        }
        idx+=idx&-idx;
    }
}
vector<int> v;
int main()
{
	int i,j,k,mc=0,x=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        res[i]=Max(a[i]-1);///res[i]=Max(a[i]) //if "Non Decreasing!"
        append(a[i],i,res[i].X+1);
        if(mc<res[i].X)
            mc=res[i].X,x=i;
    }
    while(x)
    {
        v.emplace_back(a[x]);///v.emplace_back(x);
        x=res[x].Y;
    }
    for(i=v.size()-1;i>=0;i--)
        printf("%d ",v[i]);
}
