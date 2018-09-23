#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
int r,c,n,TEST,T,stx,sty;
char maps[135][135];
int d[1135],aa,bb;
int jum[5][1135][1135];
vector<pair<int,int> > ghost[1135];
int dx[6]={1,-1,0,0},dy[6]={0,0,1,-1};
queue<tuple<int,int,int,int> > q;
int main()
{
    int i,j,k,x,y,t,type,fu=0;
    scanf("%d",&TEST);
    while(TEST--)
    {
        memset(maps,0,sizeof maps);
        scanf("%d %d %d %d %d %d",&r,&c,&n,&T,&stx,&sty);
        stx++;sty++;fu=0;
        for(i=0;i<=1005;i++)
            ghost[i].clear();
        for(i=1;i<=n;i++)
        {
            scanf("%d %d %d",&d[i],&aa,&bb);
            aa++;bb++;
            ghost[d[i]].emplace_back(aa,bb);
            //printf("%d %c\n",d[i],maps[aa][bb]);

        }
        for(i=1;i<=r;i++)
        {
            scanf("%s",maps[i]+1);
        }
        for(i=0;i<ghost[0].size();i++)
        {
            if(maps[ghost[0][i].X][ghost[0][i].Y]=='.')
            {
                maps[ghost[0][i].X][ghost[0][i].Y]='X';
                q.emplace(0,1,ghost[0][i].X,ghost[0][i].Y);
            }
        }
        if(maps[stx][sty]=='.')
        {
            maps[stx][sty]='Y';
            q.emplace(1,1,stx,sty);
        }
        while(!q.empty())
        {
            tie(type,t,x,y)=q.front();
            q.pop();
//            printf("= %d %d %d %d =\n",type,t,x,y);
//            for(i=1;i<=r;i++)
//            {
//                printf("%s\n",maps[i]+1);
//            }
//            system("pause");
            if(t>=T+1)
            {
                if(type==1)
                {
                    fu=1;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(type==1)
            {
                if(!ghost[t].empty())
                {
                    for(i=0;i<ghost[t].size();i++)
                    {
                        if(maps[ghost[t][i].X][ghost[t][i].Y]=='.'||maps[ghost[t][i].X][ghost[t][i].Y]=='Y')
                        {
                            //printf("%d %d\n",ghost[t][i].X,ghost[t][i].Y);
                            maps[ghost[t][i].X][ghost[t][i].Y]='X';
                            q.emplace(0,t+1,ghost[t][i].X,ghost[t][i].Y);
                        }
                    }
                    ghost[t].clear();
                }
                if(maps[x][y]=='Y')
                    q.emplace(1,t+1,x,y);
            }
            for(j=0;j<4;j++)
            {
                if(x+dx[j]>=1&&x+dx[j]<=r&&y+dy[j]>=1&&y+dy[j]<=c)
                {
                    if(type==1)
                    {
                        if(maps[x+dx[j]][y+dy[j]]=='.')
                        {
                            maps[x+dx[j]][y+dy[j]]='Y';
                            q.emplace(type,t+1,x+dx[j],y+dy[j]);
                        }
                    }
                    else
                    {
                        if(maps[x+dx[j]][y+dy[j]]=='.'||maps[x+dx[j]][y+dy[j]]=='Y')
                        {
                            maps[x+dx[j]][y+dy[j]]='X';
                            q.emplace(type,t+1,x+dx[j],y+dy[j]);
                        }
                    }

                }
            }
        }
        while(!q.empty())
            q.pop();
//        for(i=1;i<=r;i++)
//        {
//            for(j=1;j<=c;j++)
//            {
//                if(maps[i][j]=='Y')
//                {
//                    fu=1;
//                    break;
//                }
//            }
//        }
        if(fu==1)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }

    }
}
