#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
queue<pair<int,int> > q;
int maps[10][10];
int dx[12]={-1,1,-1,0,1,-1,0,1};
int dy[12]={0,-1,-1,-1,1,1,1};
int chk(int x,int y)
{
    if(x>=1&&x<=8&&y>=1&&y<=8&&maps[x][y]==0)
        return 1;
    return 0;
}
int main()
{
    int a,b,c,d,x,y,i,j,t=0;
    while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&x,&y)!=EOF)
    {
        t++;
        memset(maps,0,sizeof maps);
        maps[x][y]=-1;
        q.emplace(a,b);
        maps[a][b]=1;
        while(!q.empty())
        {
           tie(x,y)=q.front();
           q.pop();
    //       printf("%d %d\n",x,y);
           for(i=0;i<8;i++)
           {
                if(chk(x+dx[i],y+dy[i]))
                {
                    maps[x+dx[i]][y+dy[i]]=maps[x][y]+1;
                    q.emplace(x+dx[i],y+dy[i]);
                }
           }
        }
    //    for(i=1;i<=8;i++)
    //    {
    //        for(j=1;j<=8;j++)
    //            printf("%d ",maps[i][j]);
    //        printf("\n");
    //    }
        printf("Case %d: %d\n",t,maps[c][d]-1);
    }
}
