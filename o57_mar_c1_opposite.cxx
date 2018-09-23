#include<bits/stdc++.h>
using namespace std;
char maps[33][33];
int n,m,state[33][33][33][33],Dist[33][33][33][33],jum[33][33],Min=1000000000;
int dx[6]={1,-1,0,0},dy[6]={0,0,1,-1},aa,bb,cc,dd,a,b,c,d;
queue<tuple<int,int,int,int> > q;
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
    int i,j,k,l,A,B,C,D;
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
    for(i=0;i<=n+1;i++)
        for(j=0;j<=m+1;j++)
            for(k=0;k<=n+1;k++)
                for(l=0;l<=m+1;l++)
                    Dist[i][j][k][l]=1000000000;
    Dist[a][b][c][d]=0;
    q.emplace(a,b,c,d);
    memset(state,0,sizeof state);
    while(!q.empty())
    {
        tie(a,b,c,d)=q.front();
        q.pop();

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
                if(abs(C-A)+abs(D-B)<Min)
                {
                    Min=abs(C-A)+abs(D-B);
                    aa=A;bb=B;cc=C;dd=D;
                }
            }
        }
    }
    if(Min==1000000000)
        printf("-1 0\n");
    else
        printf("%d %d",Min,Dist[aa][bb][cc][dd]);
}
