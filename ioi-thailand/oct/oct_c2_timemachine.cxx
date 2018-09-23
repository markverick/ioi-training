#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int x[13],y[13],d[13],jum[13][10135],n;
inline int dist(const int x,const int y)
{
    return nearbyint(ceil(sqrt(x*x+y*y)));
}
int dp(int idx,int bit)
{
    if(jum[idx][bit]>=0)return jum[idx][bit];
    if(idx==n+1)
    {
        return 0;
    }
    int mn=MI,i;
    for(i=1;i<=n+1;i++)
    {
        if(((1<<i)|bit)==bit)continue;
        mn=min(mn,dp(i,bit|(1<<i))+dist(x[idx]-x[i],y[idx]-y[i])-d[i]);
    }
    return jum[idx][bit]=mn;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    int m,i,j,k,r,c;
    memset(jum,-1,sizeof jum);
    scanf("%d %d %d",&r,&c,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&x[i],&y[i],&d[i]);
    }
    x[n+1]=r-1;y[n+1]=c-1;d[n+1]=0;
    printf("%d",dp(0,0));
}
