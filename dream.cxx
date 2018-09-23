#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
#define MI 1000000000
using namespace std;
queue<tuple<int,int,int> > q;
int maps[1135][1135];
int step[1135][1135][3];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
int n,m;
int chk(int x,int y)
{
    if(x>=1&&y>=1&&x<=n&&y<=m)
    {
        if(maps[x][y]!=0)
            return maps[x][y];
    }
    return 0;
}
int main()
{
    int i,j,k;
    freopen("dream.in","r",stdin);
    freopen("dream.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&maps[i][j]);
            step[i][j][0]=MI;
            step[i][j][1]=MI;
        }
    }
    step[1][1][0]=1;
    q.emplace(1,1,0);
    int x,y,o,ch;
    while(!q.empty())
    {
        tie(x,y,o)=q.front();
        q.pop();
//        printf("%d %d %d\n",x,y,o);
        for(i=0;i<4;i++)
        {
            if(chk(x+dx[i],y+dy[i])==0)
                continue;
            ch=maps[x+dx[i]][y+dy[i]];
            if(ch==1)
            {
                if(step[x+dx[i]][y+dy[i]][o]<=step[x][y][o]+1)continue;
                step[x+dx[i]][y+dy[i]][o]=step[x][y][o]+1;
                q.emplace(x+dx[i],y+dy[i],o);
            }
            else if(ch==2)
            {
                if(step[x+dx[i]][y+dy[i]][1]<=step[x][y][o]+1)continue;
                step[x+dx[i]][y+dy[i]][1]=step[x][y][o]+1;
                q.emplace(x+dx[i],y+dy[i],1);
            }
            else if(ch==3)
            {
                if(o==0||step[x+dx[i]][y+dy[i]][o]<=step[x][y][o]+1)
                    continue;
                step[x+dx[i]][y+dy[i]][o]=step[x][y][o]+1;
                q.emplace(x+dx[i],y+dy[i],o);
            }
            else if(ch==4)
            {
                k=2;
                while(chk(x+k*dx[i],y+k*dy[i])==4)
                {
                    k++;
                }
                if(chk(x+k*dx[i],y+k*dy[i])==0||chk(x+k*dx[i],y+k*dy[i])==3)
                {
                    if(step[x+(k-1)*dx[i]][y+(k-1)*dy[i]][0]<=step[x][y][o]+k-1)
                        continue;
                    step[x+(k-1)*dx[i]][y+(k-1)*dy[i]][0]=step[x][y][o]+k-1;
                    q.emplace(x+(k-1)*dx[i],y+(k-1)*dy[i],0);
                }
                else if(chk(x+k*dx[i],y+k*dy[i])==2)
                {
                    if(step[x+k*dx[i]][y+k*dy[i]][1]<=step[x][y][o]+k)
                        continue;
                    step[x+k*dx[i]][y+k*dy[i]][1]=step[x][y][o]+k;
                    q.emplace(x+k*dx[i],y+k*dy[i],1);
                }
                else
                {
                    if(step[x+k*dx[i]][y+k*dy[i]][0]<=step[x][y][o]+k)
                        continue;
                    step[x+k*dx[i]][y+k*dy[i]][0]=step[x][y][o]+k;
                    q.emplace(x+k*dx[i],y+k*dy[i],0);
                }
            }
        }
    }
    if(step[n][m][0]!=MI&&step[n][m][1]!=MI)
    {
        printf("%d",min(step[n][m][0],step[n][m][1])-1);
    }
    else if(step[n][m][0]==MI&&step[n][m][1]==MI)
    {
        printf("-1");
    }
    else
    {
        printf("%d",min(step[n][m][0],step[n][m][1])-1);
    }
}
