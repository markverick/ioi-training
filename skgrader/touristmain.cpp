#include<stdio.h>
#include<algorithm>
using namespace std;
int n,k,c;
int h[1200000];
int jum[5000][5000];
int dp(int idx,int money)
{
    if(idx<4999&&money<4999&&jum[idx][money]>=0)
        return jum[idx][money];
    if(money>=k)
    {
        return 0;
    }
    if(idx<4999&&money<4999)
        return jum[idx][money] = max(dp(idx+1,money+2)+h[idx],dp(idx+1,money+1));
    else
        return max(dp(idx+1,money+2)+h[idx],dp(idx+1,money+1));
}
int main()
{
    scanf("%d %d",&n,&k);
    memset(jum,-1,sizeof jum);
    int i,j,k;
    for(i=0;i<n;i++)
    {
        scanf("%d",&h[i]);

    }
    printf("%d",dp(0,0));
}
