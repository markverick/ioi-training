#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int maps[135][135];
vector<pair<int,int> > v[135][135];
queue<pair<int,int> > q;
int dx[6]={0,0,1,-1};
int dy[6]={1,-1,0,0};
int n;
int chk(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=n)
        return 1;
    return 0;
}
int main()
{
    freopen("lightson.in","r",stdin);
    freopen("lightson.out","w",stdout);
    int m,i,j,k,a,b,x,y,x2,y2;
    scanf("%d %d",&n,&m);
    maps[1][1]=2;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&a,&b,&x,&y);
        v[a][b].emplace_back(x,y);
    }
    q.emplace(1,1);
    while(!q.empty())
    {
        x=q.front().X;y=q.front().Y;
        q.pop();
        for(i=0;i<v[x][y].size();i++)
        {
            x2=v[x][y][i].X;y2=v[x][y][i].Y;
            if(maps[x2][y2]==2)
                continue;
            maps[x2][y2]=1;
            for(j=0;j<4;j++)
            {
                if(chk(x2+dx[j],y2+dy[j])&&maps[x2+dx[j]][y2+dy[j]]==2)
                {
                    maps[x2][y2]=2;
                    q.emplace(x2,y2);
                    break;
                }
            }
        }
        for(i=0;i<4;i++)
        {
            if(chk(x+dx[i],y+dy[i])&&maps[x+dx[i]][y+dy[i]]==1)
            {
                q.emplace(x+dx[i],y+dy[i]);
                maps[x+dx[i]][y+dy[i]]=2;
            }
        }
    }
    int cot=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(maps[i][j]>=1)
                cot++;
//            printf("%d ",maps[i][j]);
        }
//        printf("\n");
    }
    printf("%d",cot);
}
