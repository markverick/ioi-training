#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> x,y;
vector<int>::iterator it;
unordered_map<int,int> xx,yy;
int a[2135],b[2135],c[2135],d[2135];
int ft[2135][3135];
int MaxX,MaxY;
void inv(int a,int b)
{
//    a=xx[a];b=yy[b];
    while(b<=y.size()+5)
    {
        ft[a][b]^=1;
        b+=b&-b;
    }
}
int chk(int x,int y)
{
    int sm=0;
    while(y>0)
    {
        sm^=ft[x][y];
        y-=y&-y;
    }
    return sm;
}
int add(int id)
{
    int i,st=xx[a[id]],ed=xx[a[id]+c[id]];
    for(i=st;i<ed;i++)
    {
        inv(i,yy[b[id]]+1);
        inv(i,yy[b[id]+d[id]]+1);
    }
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a[i],&b[i],&c[i],&d[i]);
//        a[i]++;b[i]++;
        x.emplace_back(a[i]);
//        x.emplace_back(a[i]-1);
        x.emplace_back(a[i]+c[i]);
//        x.emplace_back(a[i]+c[i]-1);
        y.emplace_back(b[i]);
//        y.emplace_back(b[i]-1);
        y.emplace_back(b[i]+d[i]);
        y.emplace_back(b[i]+d[i]-1);
    }
    sort(x.begin(),x.end());
    it=unique(x.begin(),x.end());
    x.resize(distance(x.begin(),it));
    sort(y.begin(),y.end());
    it=unique(y.begin(),y.end());
    y.resize(distance(y.begin(),it));
    for(i=0;i<x.size();i++)
        xx[x[i]]=i;
    for(i=0;i<y.size();i++)
        yy[y[i]]=i;
    for(i=1;i<=n;i++)
    {
        add(i);
    }
    int sum=0,tmp,ss;
    for(i=1;i<x.size();i++)
    {
        tmp=x[i]-x[i-1];
        ss=0;
        for(j=1;j<y.size();j++)
        {
            if(chk(i-1,j))
                ss+=(y[j]-y[j-1]);
        }
        sum+=ss*tmp;
    }
    printf("%d",sum);
}
