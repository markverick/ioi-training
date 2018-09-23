#include<bits/stdc++.h>
using namespace std;
char maps[1135][1135];
int xx[10]={1,1,2,2,-1,-1,-2,-2};
int xy[10]={1,-1,2,-2,-1,1,-2,2};
int px[6]={1,0,0,-1};
int py[6]={0,1,-1,0};
int cot=0;
int main()
{
    int r,c,i,j,k;
    scanf("%d %d",&r,&c);
    for(i=2;i<=r+1;i++)
    {
        scanf("%s",maps[i]+2);
        for(j=2;j<=c+2;j++)
        {
            if(maps[i][j]=='A')
                cot++;
        }
    }
    for(i=2;i<=r+1;i++)
    {
        for(j=2;j<=c+1;j++)
        {
            if(maps[i][j]=='x')
            {
                for(k=0;k<8;k++)
                {
                    if(maps[i+xx[k]][j+xy[k]]=='A')
                    {
                        maps[i+xx[k]][j+xy[k]]='.';
                        cot--;
                    }
                }
                maps[i][j]='.';
            }
            if(maps[i][j]=='+')
            {
                for(k=0;k<8;k++)
                {
                    if(maps[i+px[k]][j+py[k]]=='A')
                    {
                        maps[i+px[k]][j+py[k]]='.';
                        cot--;
                    }
                }
                maps[i][j]='.';
            }
        }
    }
    printf("%d\n",cot);
    for(i=2;i<=r+1;i++)
    {
        printf("%s\n",maps[i]+2);
    }
}
