#include<bits/stdc++.h>
using namespace std;

int r,c;
char maps[35][35];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
int hsh[35][35];
//int jum[35][35]=0;
int chk(int x,int y)
{
    if(x>=1&&y>=1&&x<r&&y<c&&maps[x][y]=='.'&&maps[x][y+1]=='.'&&maps[x+1][y]=='.'&&maps[x+1][y+1]=='.')
        return 1;
    else
        return 0;
}
int dp(int x,int y)
{
    if(x==r-1)
    {
        return 1;
    }
    int mc=0,i;
    for(i=0;i<4;i++)
    {
        if(hsh[x+dx[i]][y+dy[i]]==1)
            continue;
        if(chk(x+dx[i],y+dy[i])==0)
            continue;
        hsh[x+dx[i]][y+dy[i]]=1;
        mc=max(mc,dp(x+dx[i],y+dy[i]));
        hsh[x+dx[i]][y+dy[i]]=0;
    }
    return mc;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    int mc=0;
    for(i=1;i<c;i++)
    {
        if(chk(1,i)==1)
        {
            mc=max(mc,dp(1,i));
        }
    }
    if(mc==1)
        printf("yes\n");
    else
        printf("no\n");
}
