#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int maps[40135][30];
int qs[40135][30];
void Swap(pair<int,int> *p,pair<int,int> *q)
{
    pair<int,int> tmp=*p;
    *p=*q;
    *q=tmp;
}
int main()
{
    int n,m,i,j,k;
    pair<int,int> a,b;
    scanf("%d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a.X,&a.Y,&b.X,b.Y);
        if(b>a)
            Swap(a,b);
        if(a.X-a.Y>=-k&&a.X-a.Y<=k)
            qs[a.X-a.Y+k+1][a.Y]+=1;
        else if(a.X-a.Y<-k)
            qs[1][a.Y]+=1;
        else if(a.X-a.Y>k)
    }
}
