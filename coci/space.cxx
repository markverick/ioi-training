#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
vector<tuple<int,int,int,int,int,int> > x;
int ft[4][1005][1005],fn[6][1005];
void add2(int x,int y,int val,int t)
{
    int tmp=y;
    while(x<=999)
    {
        y=tmp;
        while(y<=999)
        {
            ft[t][x][y]+=val;
            y+=y&-y;
        }
        x+=x&-x;
    }
}
int sum2(int x,int y,int t)
{
    int sm=0,tmp=y;
    while(x>0)
    {
        y=tmp;
        while(y>0)
        {
            sm+=ft[t][x][y];
            y-=y&-y;
        }
        x-=x&-x;
    }
    return sm;
}
void add(int idx,int val,int t)
{
    while(idx<=999)
    {
        fn[t][idx]+=val;
        idx+=idx&-idx;
    }
}
int sum(int idx,int t)
{
    int sm=0;
    while(idx>0)
    {
        sm+=fn[t][idx];
        idx-=idx&-idx;
    }
    return sm;
}
int sumh(int a1,int b1,int a2,int b2,int i)
{
    return sum2(a2,b2,i)-sum2(a2,b1-1,i)-sum2(a1-1,b2,i)+sum2(a1-1,b1-1,i);
}
int main()
{
//    freopen("out.txt","w",stdout);
//	freopen("in.txt","r",stdin);
	int i,j,k,n,a1,b1,c1,a2,b2,c2,a,b,ch;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d %d %d",&a1,&b1,&c1,&a2,&b2,&c2);
        if(a1>a2)swap(a1,a2);
        if(b1>b2)swap(b1,b2);
        if(c1>c2)swap(c1,c2);
        x.emplace_back(c1,0,a1,b1,a2,b2);
        x.emplace_back(c2,1,a1,b1,a2,b2);
    }
    sort(x.begin(),x.end());
    long long sm=0,S=0;
    k=0;
    for(i=0;i<x.size();i++)
    {
        sm=0;
        tie(c1,ch,a1,b1,a2,b2)=x[i];
        if(ch==0)
        {
            sm+=sum(b1-1,0);
            sm+=sum(a1-1,1);
            sm+=sum(999,2)-sum(b2,2);
            sm+=sum(999,3)-sum(a2,3);
            sm-=sumh(a2+1,b2+1,999,999,0);
            sm-=sumh(a2+1,1,999,b1-1,1);
            sm-=sumh(1,b2+1,a1-1,999,2);
            sm-=sumh(1,1,a1-1,b1-1,3);
            add2(a1,b1,1,0);
            add2(a1,b2,1,1);
            add2(a2,b1,1,2);
            add2(a2,b2,1,3);
            add(b2,1,0);
            add(a2,1,1);
            add(b1,1,2);
            add(a1,1,3);
            S+=k-sm;
            k++;
        }
        else
        {
            add2(a1,b1,-1,0);
            add2(a1,b2,-1,1);
            add2(a2,b1,-1,2);
            add2(a2,b2,-1,3);
            add(b2,-1,0);
            add(a2,-1,1);
            add(b1,-1,2);
            add(a1,-1,3);
            k--;
        }
    }
    printf("%lld",S);
}
