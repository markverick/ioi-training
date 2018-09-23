#include<bits/stdc++.h>
using namespace std;
int a[55][3135];
int d[5]={-1,0,1},n,m;
int jum[52][52][3005][2][2];
int dp(int x,int y,int time,int xx,int yy)
{
    if(jum[x][y][time][xx][yy]>=0)
        return jum[x][y][time][xx][yy];
    int i,j;
    if(time>m)
    {
        return 0;
    }
    int mc=0,tmp;
    if(x==y)
        tmp=a[x][time];
    else
        tmp=a[x][time]+a[y][time];
    if(x-1>=1&&y-1>=1)
        mc=max(mc,dp(x-1,y-1,time+1,0,0));
    if(x-1>=0&&y+1<=n)
        mc=max(mc,dp(x-1,y+1,time+1,0,0));
    if(x+1<=n&&y-1>=1)
        mc=max(mc,dp(x+1,y-1,time+1,0,0));
    if(x+1<=n&&y+1<=n)
        mc=max(mc,dp(x+1,y+1,time+1,0,0));
    if(x-1>=1&&yy<1)
        mc=max(mc,dp(x-1,y,time+1,0,yy+1));
    if(x+1<=n&&yy<1)
        mc=max(mc,dp(x+1,y,time+1,0,yy+1));
    if(xx<1&&y-1>=1)
        mc=max(mc,dp(x,y-1,time+1,xx+1,0));
    if(xx<1&&y+1<=n)
        mc=max(mc,dp(x,y+1,time+1,xx+1,0));
    if(xx<1&&yy<1)
        mc=max(mc,dp(x,y,time+1,xx+1,yy+1));
    return jum[x][y][time][xx][yy]=mc+tmp;
}
int main()
{
    memset(jum,-1,sizeof jum);
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("%d",dp(1,n,1,0,0));
}
