#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int x1[41000],yy1[41000],x2[41000],y2[41000],a[12000],b[12000];
int mx[100135],my[100135];
unordered_map<int,unordered_map<int,int> > ft;
vector<int> x,y;
void add(int xx,int yy,int val)
{
    int tmp=yy;
    while(xx<=x.size()+1)
    {
        yy=tmp;
        while(yy<=y.size()+1)
        {
            ft[xx][yy]+=val;
            yy+=yy&-yy;
        }
        xx+=xx&-xx;
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
    int n,m,i,j,k;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&x1[i],&yy1[i],&x2[i],&y2[i]);
        x1[i]++;x2[i]++;yy1[i]++;y2[i]++;
        if(x2[i]<x1[i])
            Swap(&x1[i],&x2[i]);
        if(y2[i]<yy1[i])
            Swap(&yy1[i],&y2[i]);
        x.emplace_back(x1[i]);
        x.emplace_back(x2[i]);
        y.emplace_back(yy1[i]);
        y.emplace_back(y2[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        a[i]++;b[i]++;
        x.emplace_back(a[i]);
        y.emplace_back(b[i]);
    }
//    x.emplace_back(0);
//    x.emplace_back(100005);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    auto it=unique(x.begin(),x.end());
    x.resize(distance(x.begin(),it));
    it=unique(y.begin(),y.end());
    y.resize(distance(y.begin(),it));
    for(i=0;i<x.size();i++)
    {
        mx[x[i]]=i+1;
    }
    for(i=0;i<y.size();i++)
    {
        my[y[i]]=i+1;
    }
    for(i=1;i<=n;i++)
    {
        add(mx[x1[i]],my[yy1[i]],1);
        add(mx[x2[i]]+1,my[yy1[i]],-1);
        add(mx[x1[i]],my[y2[i]]+1,-1);
        add(mx[x2[i]]+1,my[y2[i]]+1,1);
    }
    for(i=1;i<=m;i++)
    {
        printf("%d\n",sum(mx[a[i]],my[b[i]]));
    }
}
