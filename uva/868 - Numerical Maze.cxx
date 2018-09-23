#include<bits/stdc++.h>
using namespace std;
int maps[135][135];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
int r,c;
int jum[105][105][105];
queue<tuple<int,int,int> > q;
int chk(int x,int y)
{
    if(x>=1&&x<=r&&y>=1&&y<=c)
    {
        return 1;
    }
    return 0;
}
int main()
{
//    freopen("out.txt","w",stdout);
    int T,i,j,k,tmp,x,y,t,mn,mc,d;
    scanf("%d",&T);
    d=T;
    while(T--)
    {
        if(T+1<d)
            printf("\n");
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                scanf("%d",&maps[i][j]);
            }
        }
        for(i=1;i<=c;i++)
        {
            if(maps[1][i]==1)
            {
                mc=0;mn=1000000000;
                q.emplace(1,1,i);
                while(!q.empty())
                {
                    tie(t,x,y)=q.front();
                    q.pop();
//                    printf("%d %d %d\n",t,x,y);
                    if(x==r)
                    {
                        mn=min(mn,y);
                        continue;
                    }
                    mc=max(mc,t);
                    if(maps[x][y]==t)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(chk(x+dx[j],y+dy[j])==0||maps[x+dx[j]][y+dy[j]]!=1)
                                continue;
                            if(jum[t+1][x+dx[j]][y+dy[j]])
                                continue;
                            jum[t+1][x+dx[j]][y+dy[j]]=1;
                            q.emplace(t+1,x+dx[j],y+dy[j]);
                        }
                    }
                    for(j=0;j<4;j++)
                    {
                        if(chk(x+dx[j],y+dy[j])==0||maps[x+dx[j]][y+dy[j]]!=maps[x][y]+1)
                            continue;
                        if(jum[t][x+dx[j]][y+dy[j]])
                            continue;
                        jum[t][x+dx[j]][y+dy[j]]=1;
                        q.emplace(t,x+dx[j],y+dy[j]);
                    }
                }
                for(j=0;j<=mc;j++)
                {
                    memset(jum[j],0,sizeof jum[j]);
                }
                if(mn<1000000000)
                {
                    printf("%d %d\n%d %d\n",1,i,r,mn);break;
                }
            }
        }
    }
}
