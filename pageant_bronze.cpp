#include<bits/stdc++.h>

char maps[60][60];
int chk[60][60];
int x[3600];
int y[3600];
int p[3600];
int q[3600];
int a[3600];
int b[3600];
int fst=0,lst=0;
//bool chk[60][60];
int r,c;
int n,m;
char sel='1';
void dfs(int x,int y);
void nq(int x,int y)
{
    //printf("N");
    if(x>=1&&x<=r&&y>=1&&y<=c&&maps[x][y]!=1&&chk[x][y]==0)
    {
        //printf("%d %d\n",x,y);
        a[lst]=x;b[lst++]=y;
        chk[x][y]=chk[n][m]+1;

    }
}
void go(int x,int y)
{
    if(maps[x][y]=='X')
    {
        maps[x][y]=sel;
        //chk[x][y]=1;
        dfs(x,y);
    }
}
void dfs(int x,int y)
{
    go(x+1,y);
    go(x-1,y);
    go(x,y+1);
    go(x,y-1);
    return;
}

int main()
{
    int i,j,k;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='X')
            {
                maps[i][j]=sel;
                dfs(i,j);
                sel++;
            }
        }
    }
    /*for(i=1;i<=r;i++)
    {
        printf("%s\n",maps[i]+1);
    }*/
    int idx1=0;
    int idx2=0;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='1')
            {
                a[lst]=i;
                b[lst++]=j;
                chk[i][j]=1;
            }
        }
    }
    while(true)
    {
        //printf("N");
        idx1++;
        n=a[fst];m=b[fst];
        //printf("%d %d\n",n,m);
       //system("pause");
        if(maps[n][m]=='2')
            break;
        fst++;
        nq(n+1,m);
        nq(n-1,m);
        nq(n,m+1);
        nq(n,m-1);
    }
    printf("%d\n",chk[n][m]-2);
    /*for(i=0;i<idx1;i++)
    {
        n=x[i];m=y[i];
        nq(n+1,m);
        nq(n-1,m);
        nq(n,m+1);
        nq(n,m-1);
    }*/
    /*for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            printf("%d",chk[i][j]);
        }
        printf("\n");
    }*/
}
