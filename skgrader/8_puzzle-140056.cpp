#include<stdio.h>
#include<stdlib.h>

int maps[5][5];
int pro[5][5];
bool chk[5][5];
char result[1000000];
void pretty_print(int idx)
{
    int i,j;
    printf("== [ %d ] ==\n",idx);
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            printf("%d ",maps[i][j]);
        }
        printf("\n");
    }
}
void swap(int *a,int *b)
{
    int c=*a;
    *a=*b;
    *b=c;
}
void dp(int x,int y,int idx);
void go(int x,int y,int idx)
{
    if(x>=1&&x<=3&&y>=1&&y<=3)
    {
        dp(x,y,idx);
    }
}
void dp(int x,int y,int idx)
{
    int i,j,k;
    int cot=0;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(maps[i][j]==pro[i][j]/*3*(i-1)+j*/)
            {
                cot++;
            }
        }
    }
    //printf(" -> %d\n",cot);
    //pretty_print(idx);
    //system("pause");
    if(cot>=8)
    {
        for(i=0;i<idx;i++)
            printf("%c",result[i]);
        //printf("%s",result);
        exit(0);
    }
    chk[x][y]=1;
    result[idx]='D';    swap(&maps[x+1][y],&maps[x][y]);
    if(!chk[x+1][y])go(x+1,y,idx+1);          swap(&maps[x+1][y],&maps[x][y]);
    result[idx]='U';    swap(&maps[x-1][y],&maps[x][y]);
    if(!chk[x-1][y])go(x-1,y,idx+1);          swap(&maps[x-1][y],&maps[x][y]);
    result[idx]='R';    swap(&maps[x][y],&maps[x][y+1]);
    if(!chk[x][y+1])go(x,y+1,idx+1);          swap(&maps[x][y],&maps[x][y+1]);
    result[idx]='L';    swap(&maps[x][y],&maps[x][y-1]);
    if(!chk[x][y-1])go(x,y-1,idx+1);          swap(&maps[x][y],&maps[x][y-1]);
    chk[x][y]=0;
}
int main()
{
    int i,j,k;
    int x,y;
    k=1;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            pro[i][j]=k++;
            scanf("%d",&maps[i][j]);
            if(maps[i][j]==0)
            {
                x=i;y=j;
            }
        }
    }
    pro[3][3]=0;
    dp(x,y,0);
}
