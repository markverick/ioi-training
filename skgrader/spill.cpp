#include<bits/stdc++.h>
int n,m,l;
char maps[120][120];
char chk[120][120];
int c=0;
int fk=1;
void fx(int x,int y);
void spill(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m&&chk[x][y]==0)
    {
        if(maps[x][y]=='*')
        {
            chk[x][y]=1;
            fx(x,y);

        }
        else if(maps[x][y]=='.')
        {
            c++;
            chk[x][y]=1;
            fx(x,y);
        }
    }
    return;
}
void fx(int x,int y)
{
    if(c>=l)
    {
        fk=0;
        return;
    }
    spill(x+1,y);
    spill(x-1,y);
    spill(x,y+1);
    spill(x,y-1);
    return;
}
int main()
{
    int i,j,k;
    scanf("%d %d %d",&n,&m,&l);
    for(i=0;i<n;i++)
    {
        scanf("%s",maps[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {

            c=0;
            if(maps[i][j]=='x')
            {
                fk=1;fx(i,j);
            }

        }
    }
    if(fk==0)
    {
        printf("Umm\n");
    }
    else
    {
        printf("Yes\n");
    }
}
