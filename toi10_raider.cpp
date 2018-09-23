#include<bits/stdc++.h>
#define MT(x,y,z) make_pair(x,make_pair(y,z))
#define X first
#define Y second
using namespace std;
queue<pair<int,pair<int,int> > > q;
int r,c;
int maps[120][120];
bool chk(int x,int y,int cot)
{
    cot++;
    if(maps[x][y]==0)
        return 0;
    if(x>=1&&x<=r&&y>=1&&y<=c&&cot%maps[x][y]==0)
        return 1;
    else
        return 0;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }
    if(maps[(r+1)/2-1][1]==1)
        q.push(MT(1,(r+1)/2-1,1));
    if(maps[(r+1)/2+1][1]==1)
        q.push(MT(1,(r+1)/2+1,1));
    if(maps[(r+1)/2][1]==1)
        q.push(MT(1,(r+1)/2,1));
    while(!q.empty())
    {
        int x=q.front().Y.X;
        int y=q.front().Y.Y;
        int cot=q.front().X;
        q.pop();
        //printf("%d %d %d\n",x,y,cot);
        int ch=x%2;
        if(x==(r+1)/2&&y==c)
        {
            printf("%d\n",cot);
            break;
        }
        if(ch==1)
        {
            if(chk(x,y+1,cot))  q.push(MT(cot+1,x,y+1));
            if(chk(x-1,y+1,cot))q.push(MT(cot+1,x-1,y+1));
            if(chk(x+1,y+1,cot))q.push(MT(cot+1,x+1,y+1));
            if(chk(x-1,y,cot))  q.push(MT(cot+1,x-1,y));
            if(chk(x+1,y,cot))  q.push(MT(cot+1,x+1,y));
            if(chk(x,y-1,cot)) q.push(MT(cot+1,x,y-1));
        }
        else
        {
            if(chk(x,y+1,cot))  q.push(MT(cot+1,x,y+1));
            if(chk(x-1,y-1,cot))q.push(MT(cot+1,x-1,y-1));
            if(chk(x+1,y-1,cot))q.push(MT(cot+1,x+1,y-1));
            if(chk(x-1,y,cot))  q.push(MT(cot+1,x-1,y));
            if(chk(x+1,y,cot))  q.push(MT(cot+1,x+1,y));
            if(chk(x,y-1,cot)) q.push(MT(cot+1,x,y-1));
        }
    }
}
        /*if(x>1&&y>1&&x<r&&y<c)
        {
            if(ch==1)
            {
                q.push(MT(cot+1,x,y+1)); q.push(MT(cot+1,x-1,y+1)); q.push(MT(cot+1,x+1,y+1));
                q.push(MT(cot+1,x-1,y)); q.push(MT(cot+1,x+1,y)); q.push(MT(cot+1,x,y-1));
            }
            else
            {
                q.push(MT(cot+1,x,y+1)); q.push(MT(cot+1,x-1,y-1)); q.push(MT(cot+1,x+1,y-1));
                q.push(MT(cot+1,x-1,y)); q.push(MT(cot+1,x+1,y)); q.push(MT(cot+1,x,y-1));
            }
        }*/

