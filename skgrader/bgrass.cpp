#include<bits/stdc++.h>
int r,c,cot=0;
char maps[135][135];
int hsh[135][135];
void fx(int x,int y);
void go(int i,int j)
{
    if(maps[i][j]=='#'&&i>=0&&i<r&&j>=0&&j<c&&hsh[i][j]==0)
    {
        //printf("A");
        fx(i,j);
    }
}
void fx(int x,int y)
{
    hsh[x][y]=1;
    go(x+1,y);go(x-1,y);go(x,y+1);go(x,y-1);

}
int main()
{
    int i,j,k;
    scanf("%d %d",&r,&c);
    for(i=0;i<r;i++)
    {
        scanf("%s",maps[i]);
    }
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            //printf("F");
            if(maps[i][j]=='#'&&hsh[i][j]==0)
            {
                fx(i,j);
                cot++;
            }
        }
    }
    printf("%d",cot);
}
