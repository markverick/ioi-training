#include<bits/stdc++.h>
using namespace std;
int r,c;
char maps[135][135];
int jum[135][135][5][3];
int dp(int x,int y,int d,int b)
{
    if(jum[x][y][d+1][b]>=0)
        return jum[x][y][d+1][b];
    if(maps[x][y]=='$')
        return 1;
    else if(maps[x][y]=='@')
        return 0;
    int mc=0;
    if(maps[x][y]=='.')
        mc=max(mc,dp(x+1,y,d,b));
    else if(maps[x][y]=='#')
    {
        if(y+d>=1&&y+d<=c)
            mc=max(mc,dp(x,y+d,d,b));
        else
            mc=max(mc,dp(x,y,-d,b));
        if(x<c&&b==0)
        {
            mc=max(mc,dp(x+1,y,d,1));
        }
    }
    return jum[x][y][d+1][b]=mc;
}
int main()
{
    int i,j,k,x,y,d,cot=0,b;
    scanf("%d %d",&c,&r);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    /*for(i=1;i<=c;i++)
    {
        x=1;y=i;d=-1;
        while(135)
        {
            if(maps[x][y]=='.')
                x++;
            else if(maps[x][y]=='#')
            {
                if(y+d>=1&&y+d<=c)
                    y+=d;
                else
                    d=-d;
            }
            else if(maps[x][y]=='$')
            {
                cot++;
                break;
            }
            else
                break;
        }
        x=1;y=i;d=1;
        while(135)
        {
            if(maps[x][y]=='.')
                x++;
            else if(maps[x][y]=='#')
            {
                if(y+d>=1&&y+d<=c)
                    y+=d;
                else
                    d=-d;
            }
            else if(maps[x][y]=='$')
            {
                cot++;
                break;
            }
            else
                break;
        }
    }*/
    cot=0;
    for(i=1;i<=c;i++)
    {
        cot+=dp(1,i,-1,1);
        cot+=dp(1,i,1,1);
    }
    printf("%d ",cot);
    cot=0;
    for(i=1;i<=c;i++)
    {
        cot+=dp(1,i,-1,0);
        cot+=dp(1,i,1,0);
    }
    printf("%d",cot);
}
