#include<bits/stdc++.h>
using namespace std;
char maps[135][135];
int qs[135][135];
int quick(int a,int b,int c,int d)
{
    return qs[c][d]-qs[c][b-1]-qs[a-1][d]+qs[a-1][b-1];
}
int main()
{
    int n,r,c,i,j,k;
    scanf("%d %d %d",&r,&c,&n);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=2;i<r;i++)
    {
        for(j=2;j<c;j++)
        {
            if(maps[i][j]=='*')
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+1;
            else
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    int mc=0,x,y;
    for(i=2;i<r;i++)
    {
        for(j=2;j<c;j++)
        {
            if(i+n-3<r&&j+n-3<c)
            {
                if(mc<quick(i,j,i+n-3,j+n-3))
                {
                    mc=quick(i,j,i+n-3,j+n-3);
                    x=i;y=j;
                }
            }
        }
    }
    printf("%d\n",mc);
    for(i=x-1;i<=x+n-2;i++)
    {
        maps[i][y-1]='|';
        maps[i][y+n-2]='|';
    }
    for(i=y-1;i<=y+n-2;i++)
    {
        maps[x-1][i]='-';
        maps[x+n-2][i]='-';
    }
    maps[x-1][y-1]='+';
    maps[x-1][y+n-2]='+';
    maps[x+n-2][y-1]='+';
    maps[x+n-2][y+n-2]='+';
    for(i=1;i<=r;i++)
    {
        printf("%s\n",maps[i]+1);
    }
}
