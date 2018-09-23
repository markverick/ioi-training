#include<bits/stdc++.h>
char maps[100][100];
bool chk[100][100];
int n,m,highest=0;
int cot=0;
int fx(int x,int y)
{

    if(chk[x][y]==1)
    {
        return 0;
    }
    if(maps[x][y]!='.'||x<1||x>n||y<0||y>m)
    {
        return 1;
    }
    cot++;
    //printf("%d %d\n",x,y);
    chk[x][y]=1;
    return fx(x+1,y)+fx(x-1,y)+fx(x,y+1)+fx(x,y-1);
}
int main()
{

    int i,j,k;
    char str[100];
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%s",str);
        for(j=1;j<=m;j++)
        {
            maps[i][j]=str[j-1];
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(maps[i][j]=='#')
            {
                if(maps[i+1][j]!='#')
                    maps[i+1][j]='*';
                if(maps[i-1][j]!='#')
                    maps[i-1][j]='*';
                if(maps[i][j+1]!='#')
                    maps[i][j+1]='*';
                if(maps[i][j-1]!='#')
                    maps[i][j-1]='*';
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(maps[i][j]!='.')
            {
                chk[i][j]=1;
            }
        }
    }
    int buffer=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cot=0;
            if(maps[i][j]=='.'&&chk[i][j]==0)
            {
                fx(i,j);
                buffer=cot;
                if(highest<buffer)
                    highest=buffer;
                //printf("\n-%d\n",buffer);
            }
        }
    }
    printf("%d",highest);
}

/*
for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            printf("%c",maps[i][j]);
         }
        printf("\n");
    }
*/
