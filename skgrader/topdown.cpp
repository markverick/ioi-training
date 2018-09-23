#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
int dx[6]={1,-1,0};
int dy[6]={0,0,1};
vector<string> maps;
vector<vector<int> > jum[5];
int r,c,s;
int chk(int x,int y)
{
    if(x>=1&&x<=r&&y>=1&&y<=c&&maps[x][y]=='.')
        return 1;
    else
        return 0;
}
int dp(int dir,int x,int y)
{
    if(y==c)
    {
        return 0;
    }
    printf("%d %d\n",dir,x,y);
    int mn=1000000000,i,j;
    for(i=0;i<3;i++)
    {
        if(!chk(x+dx[i],y+dy[i]))
            continue;
        if(dir==i)
            mn=min(mn,dp(i,x+dx[i],y+dy[i]));
        else
            mn=min(mn,dp(i,x+dx[i],y+dy[i])+1);
    }
    return mn;
}
int main()
{
    int i,j,k,l;
    cin >> r >> c >> s;
    for(i=0;i<3;i++)
    {
        jum[i].resize(r+5);
        for(j=0;j<=r+1;j++)
            jum[i][j].resize(c+5);
    }
    maps.resize(r+5);
    for(i=1;i<=r;i++)
    {
        cin >> maps[i];
        maps[i]="0"+maps[i];
    }
    for(i=0;i<=r;i++)
    {
        for(j=0;j<=c;j++)
        {
            for(k=0;k<3;k++)
                jum[k][i][j]=1000000000;
        }
    }
    printf("%d",dp(2,s,1));
}

