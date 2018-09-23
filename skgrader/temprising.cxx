#include<bits/stdc++.h>
using namespace std;
int maps[1005][1005],c[1005][1005],dx[6]={1,-1,0,0},dy[6]={0,0,1,-1},n;
queue<pair<int,int> > q;
int chk(int x,int y)
{
    if(x>=1&&x<=n&&y>=1&&y<=n&&maps[x][y]!=100&&c[x][y]==0)
        return 1;
    return 0;
}
int main()
{
    int i,j,k,a,b;
    scanf("%d %d %d",&n,&b,&a);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&maps[i][j]);
    c[a][b]=1;
    q.emplace(a,b);
    while(!q.empty())
    {
        tie(a,b)=q.front();
        q.pop();
        for(i=0;i<4;i++)
        {
            if(chk(a+dx[i],b+dy[i])&&maps[a+dx[i]][b+dy[i]]>maps[a][b])
                q.emplace(a+dx[i],b+dy[i]),c[a+dx[i]][b+dy[i]]=1;
        }
    }
    int mc=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(c[i][j])
                mc=max(mc,maps[i][j]);
        }
    }
    printf("%d",mc);
}
