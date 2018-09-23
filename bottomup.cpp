#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back;
using namespace std;
int dx[6]={1,-1,0};
int dy[6]={0,0,1};
vector<string> maps;
vector<vector<int> > dp[5];
int r,c,s,dp[1000135][5][3];
int chk(int x,int y)
{
    if(x>=1&&x<=r&&y>=1&&y<=c&&maps[x][y]=='.')
        return 1;
    else
        return 0;
}
int main()
{
    int i,j,k,l;
    cin >> r >> c >> s;
    for(i=0;i<3;i++)
    {
        dp[i].resize(r+5);
        for(j=0;j<=r+1;j++)
            dp[i][j].resize(c+5);
    }
    maps.resize(r+5);
    for(i=1;i<=r;i++)
    {
        cin >> maps[i];
        maps[i]="0"+maps[i];
    }
    for(i=1;i<=r;i++)
    {
        for(j=0;j<=1;j++)
        {
            for(k=0;k<3;k++)
                dp[i][k][j]=1000000000;
        }
    }
    dp[2][s][1]=0;
    for(j=1;j<=c;j++)
    {
        for(i=1;i<=r;i++)
        {
            for(k=0;k<3;k++)
                dp[k][i][1-(j%2)]=1000000000;
        }
        for(i=1;i<=r;i++)
        {
            for(k=0;k<3;k++)
            {
                if(chk(i+dx[k],j+dy[k]))
                {
                    for(l=0;l<3;l++)
                    {
                        if(k==l)
                        {
                            dp[k][i+dx[k]][j+dy[k]]=min(dp[l][i][j%2],dp[k][i+dx[k]][(j%2)^dy[k]]);
                        }
                        else
                        {
                            dp[k][i+dx[k]][j+dy[k]]=min(dp[l][i][j%2]+1,dp[k][i+dx[k]][(j%2)^dy[k]]);
                        }
                    }
                }
            }
        }
    }
    int mn=1000000000;
    for(i=1;i<=r;i++)
    {
        for(k=0;k<3;k++)
            mn=min(mn,dp[i][k][c%2]);
    }
    printf("%d",mn);
}

