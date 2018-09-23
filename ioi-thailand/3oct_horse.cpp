#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
queue<pair<int,int> >q;
int maps[1200][1200];
int xB,yB;
int n;
void push(int x,int y)
{
    //printf("%d %d\n",x,y);

    if(x>=1&&x<=n&&y>=1&&y<=n&&maps[x][y]==0)
    {
        q.push(MP(x,y));
        maps[x][y]=maps[xB][yB]+1;
    }
}
int main()
{
    int m,p,i,j,k;
    int xS,yS;
    while(scanf("%d %d %d",&n,&m,&p)!=EOF)
    {
        if(n==0&&m==0&&p==0)
            exit(0);
        memset(maps,0,sizeof maps);
        while(!q.empty())
            q.pop();
        scanf("%d %d",&xS,&yS);
        q.push(MP(xS,yS));
        maps[xS][yS]=1;
        for(i=0;i<m;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            maps[a][b]=-1;
        }
        while(!q.empty())
        {
            xB=q.front().first;
            yB=q.front().second;
            q.pop();
            push(xB+1,yB+2);
            push(xB+2,yB+1);
            push(xB-1,yB+2);
            push(xB+2,yB-1);
            push(xB+1,yB-2);
            push(xB-2,yB+1);
            push(xB-1,yB-2);
            push(xB-2,yB-1);
        }
        for(i=0;i<p;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            if(maps[a][b]==0||maps[a][b]==-1)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",maps[a][b]-1);
            }
        }
    }
}
