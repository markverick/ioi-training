#include<bits/stdc++.h>
#define MP make_pair
#define X first
#define Y second
using namespace std;
int r,c;
int maps[1200][1200];
pair<int,int> dp[1200][1200];

int main()
{
    int i,j,k;
    scanf("%d %d",&r,&c);
    //memset(jum,-1,sizeof jum);
    //memset(jumd,-1,sizeof jumd);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }/*
    for(i=1;i<=c;i++)
    {
        dp[0][i]=MP(0,1);
    }*/
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(i%2==1)
            {
                if(j-1>=1)
                {
                    if(dp[i-1][j].X==dp[i-1][j-1].X)
                    {
                        dp[i][j]=MP(dp[i-1][j].X+maps[i][j],dp[i-1][j].Y+dp[i-1][j-1].Y);
                    }
                    else if(dp[i-1][j].X>dp[i-1][j-1].X)
                    {
                        dp[i][j]=MP(dp[i-1][j].X+maps[i][j],dp[i-1][j].Y);
                    }
                    else
                    {
                        dp[i][j]=MP(dp[i-1][j-1].X+maps[i][j],dp[i-1][j-1].Y);
                    }
                    //dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+maps[i][j];
                }
                else
                    dp[i][j]=MP(dp[i-1][j].X+maps[i][j],dp[i-1][j].Y);
            }
            else
            {
                if(j+1<=c)
                {
                    if(dp[i-1][j].X==dp[i-1][j+1].X)
                    {
                        dp[i][j]=MP(dp[i-1][j].X+maps[i][j],dp[i-1][j].Y+dp[i-1][j+1].Y);
                    }
                    else if(dp[i-1][j].X>dp[i-1][j+1].X)
                    {
                        dp[i][j]=MP(dp[i-1][j].X+maps[i][j],dp[i-1][j].Y);
                    }
                    else
                    {
                        dp[i][j]=MP(dp[i-1][j+1].X+maps[i][j],dp[i-1][j+1].Y);
                    }
                    //dp[i][j]=max(dp[i-1][j],dp[i-1][j+1])+maps[i][j];
                }
                else
                    dp[i][j]=MP(dp[i-1][j].X+maps[i][j],dp[i-1][j].Y);
            }
            if(i==1)
                dp[i][j].Y=1;
        }
    }
    sort(&dp[r][1],&dp[r][c+1]);
    int mc=dp[r][c].X;
    int cot=0;
    for(i=c;i>=1;i--)
    {
        if(dp[r][i].X!=mc)
            break;
        cot+=dp[r][i].Y;
    }
    printf("%d %d\n",dp[r][c].X,cot);
}
