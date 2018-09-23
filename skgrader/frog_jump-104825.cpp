#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int r,c;
int rr[1000][1000];
int dd[1000][1000];
int jum[1000][1000];
bool chk[1000][1000];
int cleared=0;
int dp(int x,int y)
{

    //printf("%d %d\n",x,y);
    x=x%r;y=y%c;
    if(jum[x][y]>=0)
    {
        return jum[x][y];
    }
    if(chk[x][y]==1)
    {
        return 99999999;
    }
    //system("pause");
    if(x==r-1&&y==c-1)
    {
        //printf("F");
        cleared=1;
        return 0;
    }
    chk[x][y]=1;
    return jum[x][y] = 1+min(dp((x+dd[x][y])%r,y),dp(x,(y+rr[x][y])%c));
}
int main()
{
    cleared=0;
    int i,j,k;
    while(scanf("%d %d",&r,&c)!=EOF)
    {
        cleared=0;
        memset(chk,0,sizeof chk);
        memset(jum,-1,sizeof jum);
        memset(dd,-1,sizeof dd);
        memset(rr,-1,sizeof rr);
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&rr[i][j]);
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&dd[i][j]);
            }
        }
        int out=dp(0,0);
        if(cleared==1&&out!=100000000)
            printf("%d\n",dp(0,0));
        else
            printf("-1");



    }


}
