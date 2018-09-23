#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
char in[2];
char maps[1200][1200];
bool chk[1200][1200];
queue<pair<int,int> >q;
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int i,j,k;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            scanf("%s",in);
            maps[i][j]=in[0];
        }
    }
    q.push(MP(0,0));
    int x=0,y=0;
    while(true)
    {
        x=q.front().first;
        y=q.front().second;
        if(chk[x][y]==0)
            chk[x][y]=1;
        else
        {
            printf("%d\n%d %d\n",x+y+1,x+1,y+1);
            exit(0);
        }
        q.pop();
        if(y-1>=0&&(maps[x][y-1]=='R'||maps[x][y-1]=='B'))
        {
            q.push(MP(x,y-1));
        }
        else if(x-1>=0&&(maps[x-1][y]=='D'||maps[x-1][y]=='B'))
        {
            q.push(MP(x-1,y));
        }
        if(maps[x][y]=='B')
        {
            q.push(MP(x+1,y));
            q.push(MP(x,y+1));
        }
        else if(maps[x][y]=='D')
        {
            q.push(MP(x+1,y));
        }
        else if(maps[x][y]=='R')
        {
            q.push(MP(x,y+1));
        }
        maps[x][y]='N';
    }
    printf("-1\n");
}
