#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
char maps[120][120];
//char chk[120][120];
queue<pair<int,int> > q;
int main()
{
    int r,c;
    while(scanf("%d %d",&r,&c)!=EOF)
    {
        while(!q.empty())
            q.pop();
        //scanf("%d %d",&r,&c);
        if(r==0&&c==0)
            exit(0);
        int i,j,k;
        memset(maps,0,sizeof maps);
        for(i=0;i<=r+1;i++)
            for(j=0;j<=c+1;j++)
                maps[i][j]='x';
        for(i=1;i<=r;i++)
        {
            scanf("%s",maps[i]+1);
        }
        for(i=0;i<=r+1;i++)
        {
                q.push(MP(i,0));
                maps[i][0]='x';
                q.push(MP(i,c+1));
                maps[i][c+1]='x';
        }
        for(i=0;i<=c+1;i++)
        {
                q.push(MP(0,i));
                maps[0][i]='x';
                q.push(MP(r+1,i));
                maps[r+1][i]='x';
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            if(maps[x+1][y]=='.')
            {
                q.push(MP(x+1,y));
                maps[x+1][y]='x';
            }
            if(maps[x-1][y]=='.')
            {
                q.push(MP(x-1,y));
                maps[x-1][y]='x';
            }
            if(maps[x][y+1]=='.')
            {
                q.push(MP(x,y+1));
                maps[x][y+1]='x';
            }
            if(maps[x][y-1]=='.')
            {
                q.push(MP(x,y-1));
                maps[x][y-1]='x';
            }
        }
        int cot=0;
        for(i=0;i<=r+1;i++)
        {
            for(j=0;j<=c+1;j++)
            {
                //printf("%c",maps[i][j]);
                if(maps[i][j]=='x')
                {
                    if(i+1<=r+1&&maps[i+1][j]=='H')
                        cot++;
                    if(i-1>=0&&maps[i-1][j]=='H')
                        cot++;
                    if(j+1<=c+1&&maps[i][j+1]=='H')
                        cot++;
                    if(j-1>=0&&maps[i][j-1]=='H')
                        cot++;
                }
            }
            //printf("\n");
        }
        printf("%d\n",cot);
    }
}
