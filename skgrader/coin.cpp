/*
6 4
xx.xxx
xNxWEx
x.xSx.
x.xxxx
*/
#include<bits/stdc++.h>
int r,c;
char maps[300][300];
bool chk[300][300];
int x[6],y[6];
int dfs(int x,int y)
{
    if(x<=1||x>=r||y<=1||y>=c)
    {
        return 1;
    }
    chk[x][y]=1;
    int hi=0;
    if(chk[x+1][y]==0&&maps[x+1][y]=='.')
        hi+=dfs(x+1,y);
    if(chk[x-1][y]==0&&maps[x-1][y]=='.')
        hi+=dfs(x-1,y);
    if(chk[x][y+1]==0&&maps[x][y+1]=='.')
        hi+=dfs(x,y+1);
    if(chk[x][y-1]==0&&maps[x][y-1]=='.')
        hi+=dfs(x,y-1);
    if(hi>0)
        return 1;
    else
        return 0;

}
int main()
{
    scanf("%d %d",&c,&r);
    int i,j,k;
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='W')
            {
                x[0]=i;y[0]=j;
            }
            if(maps[i][j]=='S')
            {
                x[1]=i;y[1]=j;
            }
            if(maps[i][j]=='E')
            {
                x[2]=i;y[2]=j;
            }
            if(maps[i][j]=='N')
            {
                x[3]=i;y[3]=j;
            }
        }
    }
    if(dfs(x[0],y[0])==1)
    {
        printf("W");exit(0);
    }
    memset(chk,0,sizeof chk);
    if(dfs(x[1],y[1])==1)
    {
        printf("S");exit(0);
    }
    memset(chk,0,sizeof chk);
    if(dfs(x[2],y[2])==1)
    {
        printf("E");exit(0);
    }
    memset(chk,0,sizeof chk);
    if(dfs(x[3],y[3])==1)
    {
        printf("N");exit(0);
    }
    printf("Bye");
}
