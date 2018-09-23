#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define X first
#define Y second
using namespace std;
int n;
char maps[7][1135];
bool adj[6][2005][6][2005];
int mat[6][2005][6][2005];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
inline int isIn(int x,int y)
{
    if(x>=1&&x<=5&&y>=1&&y<=n)
        return 1;
    return 0;
}
int dfs(int x,int y)
{
    int sum;
    if(maps[x][y]=='@')
    {
        return 0;
    }
    int i;
    if(y>n)
    {
        if(adj[x][y][x][y-n]>0)
        {
            return dfs(x,y-n)+mat[x][y-n][x][y];
        }
    }
    else
    {
        for(i=0;i<4;i++)
        {
            if(isIn(x+dx[i],y+dy[i])&&adj[x][y][x+dx[i]][n+y+dy[i]]>0)
            {
                sum+=dfs(x+dx[i],y+dy[i]+n);
            }
        }
    }
    return sum;
}
queue<pair<int,int> > q;
int hsh[6][2005];
int dist[6][2005];
pair<int,int> teema[6][2005],p;
vector<pair<int,int> > vec,choice;
int main()
{
//    freopen("out.txt","w",stdout);
    int i,j,k,l,u,v;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        for(i=0;i<=5;i++)
            for(j=0;j<=n*2+1;j++)
                for(k=0;k<=5;k++)
                    for(l=0;l<=n*2+1;l++)
                        mat[i][j][k][l]=0,adj[i][j][k][l]=0;
        for(i=1;i<=5;i++)
        {
            scanf("%s",maps[i]+1);
        }
        if(n==1)
        {
            printf("0\n");
            continue;
        }
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=n;j++)
            {
                for(k=0;k<4;k++)
                {
                    if(!isIn(i+dx[k],j+dy[k]))
                        continue;
                    adj[i][n+j][i+dx[k]][j+dy[k]]=1;
                }
                adj[i][j][i][n+j]=1;
                if(maps[i][j]=='@')
                {
                    adj[0][0][i][j]=1;
                }
                else
                {
                    mat[i][j][i][n+j]=maps[i][j]-'0';
                    mat[i][n+j][i][j]=-(int)(maps[i][j]-'0');
                }
            }
            adj[i][n*2][1][n*2+1]=1;
        }
        int sum=0;
        while(135)
        {
            vec.clear();
            for(i=1;i<=5;i++)
                for(j=1;j<=n*2+1;j++)
                    dist[i][j]=1000000000;
            memset(hsh,0,sizeof hsh);
            dist[0][0]=0;
            q.emplace(0,0);
            while(!q.empty())
            {
                u=q.front().X;
                v=q.front().Y;
                q.pop();
                hsh[u][v]--;
                choice.clear();
                if(u==0&&v==0)
                {
                    for(i=1;i<=5;i++)
                    {
                        if(maps[i][1]=='@')
                        {
                            choice.emplace_back(i,1);
                        }
                    }
                }
                else if(u==1&&v==n*2+1)
                {
                    for(i=1;i<=5;i++)
                    {
                        choice.emplace_back(i,n*2);
                    }
                }
                else if(v==1)
                {
                    choice.emplace_back(u,n+v);
                    if(maps[u][v]=='@')
                        choice.emplace_back(0,0);
                }
                else if(v==n+1)
                {
                    choice.emplace_back(u,v-n);
                    for(i=0;i<4;i++)
                    {
                        if(isIn(u+dx[i],v-n+dy[i]))
                            choice.emplace_back(u+dx[i],v-n+dy[i]);
                    }
                }
                else if(v==n)
                {
                    choice.emplace_back(u,v+n);
                    for(i=0;i<4;i++)
                    {
                        if(isIn(u+dx[i],v+dy[i]))
                            choice.emplace_back(u+dx[i],v+n+dy[i]);
                    }
                }
                else if(v==n*2)
                {
                    choice.emplace_back(1,n*2+1);
                    choice.emplace_back(u,v-n);
                }
                else if(v<=n)
                {
                    choice.emplace_back(u,v+n);
                    for(k=0;k<4;k++)
                    {
                        if(isIn(u+dx[k],v+dy[k]))
                            choice.emplace_back(u+dx[k],v+n+dy[k]);
                    }
                }
                else
                {
                    choice.emplace_back(u,v-n);
                    for(k=0;k<4;k++)
                    {
                        if(isIn(u+dx[k],v-n+dy[k]))
                            choice.emplace_back(u+dx[k],v-n+dy[k]);
                    }
                }
//                printf("!! %d\n",choice.size());
//                if(choice.size()==1)
//                {
//                    printf("%d %d\n",u,v);
//                }
                for(k=0;k<choice.size();k++)
                {
                    i=choice[k].X;j=choice[k].Y;
                    if(adj[u][v][i][j]>0)
                    {
                        if(dist[u][v]+mat[u][v][i][j]<dist[i][j])
                        {
                            dist[i][j]=dist[u][v]+mat[u][v][i][j];
                            teema[i][j]=make_pair(u,v);
                            if(!hsh[i][j])
                            {
                                hsh[i][j]++;
                                q.emplace(i,j);
                            }
                        }
                    }
                }
            }
            if(dist[1][n*2+1]==1000000000)
            {
                break;
            }
//            system("pause");
            sum+=dist[1][n*2+1];
            p={1,n*2+1};
            while(p.X>0)
            {
                vec.emplace_back(p.X,p.Y);
                p=teema[p.X][p.Y];
            }
            vec.emplace_back(p.X,p.Y);
            for(i=vec.size()-1;i>0;i--)
            {
                adj[vec[i].X][vec[i].Y][vec[i-1].X][vec[i-1].Y]=0;
                adj[vec[i-1].X][vec[i-1].Y][vec[i].X][vec[i].Y]=1;
            }
        }
        sum=0;
        for(i=1;i<=5;i++)
        {
            sum+=dfs(i,n*2);
        }
        printf("%d\n",sum);
    }
}
