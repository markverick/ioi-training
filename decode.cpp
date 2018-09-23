#include<bits/stdc++.h>

char maps[25][25];
int main()
{
    int r,c,x,y;
    scanf("%d %d %d %d",&r,&c,&x,&y);
    int i,j;
    for(i=1;i<=r+2;i++)
        for(j=1;j<=c+2;j++)
            maps[i][j]=' ';
    for(i=1;i<=c+2;i++)
    {
        maps[1][i]='#';
        maps[r+2][i]='#';
    }
    for(i=1;i<=r+2;i++)
    {
        maps[i][1]='#';
        maps[i][c+2]='#';
    }
    for(i=x+1,j=y+1;i<r+2&&j<c+2;i++,j++)
        maps[i][j]='*';
    for(i=x+1,j=y+1;i>1&&j<c+2;i--,j++)
        maps[i][j]='*';
    for(i=x+1,j=y+1;i<r+2&&j>1;i++,j--)
        maps[i][j]='*';
    for(i=x+1,j=y+1;i>1&&j>1;i--,j--)
        maps[i][j]='*';

    for(i=1;i<=r+2;i++)
    {
        for(j=1;j<=c+2;j++)
        {
            printf("%c",maps[i][j]);
        }
        printf("\n");
    }

    return 0;
}
