#include<bits/stdc++.h>
using namespace std;
int m,n,t;
int maps[12000][120];
int result[12000];
int jum[12000][120];
int dp(int idx,int lane)
{
    int i;
    if(jum[idx][lane]>=0)
        return jum[idx][lane];
    //printf("%d %d\n",idx,lane);
    if(idx==t)
    {
        for(i=1;i<=t;i++)
        {
            printf("%d\n",result[i]);
        }
        exit(0);
        return 1;
    }
    int ch=0;
    if(maps[idx+1][lane]==0)
    {
        result[idx+1]=3;
        ch=max(ch,dp(idx+1,lane));
    }
    if(lane-1>=1&&maps[idx+1][lane-1]==0)
    {
        result[idx+1]=1;
        ch=max(ch,dp(idx+1,lane-1));
    }
    if(lane+1<=m&&maps[idx+1][lane+1]==0)
    {
        result[idx+1]=2;
        ch=max(ch,dp(idx+1,lane+1));
    }

    return jum[idx][lane]=ch;
}
int main()
{
    int i,j,k;
    scanf("%d %d %d",&m,&n,&t);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=t;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }
    result[1]=n;
    dp(0,n);

}
