#include<bits/stdc++.h>
using namespace std;
char maps[32][32];
int n,m,state[32][32][32][32],Dist[32][32][32][32],jum[32][32],Min=1000000000;
int dx[6]={1,-1,0,0},dy[6]={0,0,1,-1},aa,bb,cc,dd,a,b,c,d;
queue<tuple<int,int,int,int> > q;
queue<pair<int,int> > qq;
int isFree(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=m&&maps[x][y]!='#')
        return 1;
    return 0;
}
int dfs(int x,int y)
{
    int i;
    jum[x][y]=1;
    if(x==c&&y==d)
    {
        return 1;
    }
    int mc=0;
    for(i=0;i<4;i++)
    {
        if(jum[x+dx[i]][y+dy[i]])
            continue;
        if(isFree(x+dx[i],y+dy[i]))
            mc=max(mc,dfs(x+dx[i],y+dy[i]));
    }
    return mc;
}
int main()
{
    int i,j,k,l,A,B,C,D,x,y,dit,xx,yy;
    scanf("%d %d",&m,&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",maps[i]+1);

        for(j=1;j<=m;j++)
        {
            if(maps[i][j]=='A')
            {
                a=i;b=j;
            }
            else if(maps[i][j]=='B')
            {
                c=i;d=j;
            }
        }
    }
    if(dfs(a,b)==0)
    {
        printf("-1 0");
        return 0;
    }
    Dist[a][b][c][d]=0;
    q.emplace(a,b,c,d);
    state[a][b][c][d]=1;
    int fu=0;
    while(!q.empty())
    {
        tie(a,b,c,d)=q.front();
        q.pop();
        if(abs(c-a)+abs(d-b)<Min)
        {
            Min=abs(c-a)+abs(d-b);
            aa=a;bb=b;cc=c;dd=d;
        }
        if(a==c&&b==d)
            fu=1;
        for(i=0;i<4;i++)
        {
            if(a+dx[i]==c&&b+dy[i]==d)
                fu=1;
        }
        for(i=0;i<4;i++)
        {
            A=a+dx[i];B=b+dy[i];C=c-dx[i];D=d-dy[i];
            if(!isFree(A,B))
                A=a,B=b;
            if(!isFree(C,D))
                C=c,D=d;
            if(state[A][B][C][D]==0)
            {
                if(A==a&&B==b&&C==c&&D==d)
                    continue;
                state[A][B][C][D]=1;
                q.emplace(A,B,C,D);
                Dist[A][B][C][D]=Dist[a][b][c][d]+1;

            }
        }
    }
    if(fu==1)
    {
        if(Min==1000000000)
            printf("-1 0\n");
        else
            printf("%d %d",Min,Dist[aa][bb][cc][dd]);
        return 0;
    }
    Min=100000000;
    while(!q.empty())
        q.pop();
    memset(Dist,0,sizeof Dist);
    memset(state,0,sizeof state);
    Dist[a][b][c][d]=0;
    q.emplace(a,b,c,d);
    state[a][b][c][d]=1;
    while(!q.empty())
    {
        tie(a,b,c,d)=q.front();
        q.pop();
        qq.emplace(a,b);
        memset(jum,0,sizeof jum);
        jum[a][b]=1;
        while(!qq.empty())
        {
            tie(x,y)=qq.front();
            qq.pop();
            for(i=0;i<4;i++)
            {
                xx=x+dx[i];yy=y+dy[i];
                if(isFree(xx,yy))
                {
                    if(jum[xx][yy])
                        continue;
                    jum[xx][yy]=jum[x][y]+1;
                    qq.emplace(xx,yy);
                }
            }
        }
        if(jum[c][d]<Min)
        {
            Min=jum[c][d];dit=Dist[a][b][c][d];
        }
        else if(jum[c][d]==Min)
        {
            dit=min(dit,Dist[a][b][c][d]);
        }
        for(i=0;i<4;i++)
        {
            A=a+dx[i];B=b+dy[i];C=c-dx[i];D=d-dy[i];
            if(!isFree(A,B))
                A=a,B=b;
            if(!isFree(C,D))
                C=c,D=d;
            if(state[A][B][C][D]==0)
            {
                if(A==a&&B==b&&C==c&&D==d)
                    continue;
                state[A][B][C][D]=1;
                q.emplace(A,B,C,D);
                Dist[A][B][C][D]=Dist[a][b][c][d]+1;

            }
        }
    }
    if(Min==1000000000)
        printf("-1 0\n");
    else
        printf("%d %d",Min-1,dit);
}
