#include<bits/stdc++.h>
using namespace std;
int r,c,t,mid,num;
int maps[531][531];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
int imp[531][531];
int state[531][531];
int ha[300000];
int hb[300000];
int valid(int a,int b,int x,int y)
{
    if(a>=1&&a<=r&&b>=1&&b<=c&&x>=1&&x<=r&&y>=1&&y<=c)
    {
        if(abs(maps[a][b]-maps[x][y])<=mid)
        {
            return 1;
        }
    }
    return 0;
}
void dfs(int x,int y)
{
    int i;
    state[x][y]=num;
    for(i=0;i<4;i++)
    {
        if(state[x+dx[i]][y+dy[i]])
            continue;
        if(valid(x,y,x+dx[i],y+dy[i]))
        {
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main()
{
    int i,j,k,cot;
    scanf("%d %d %d",&r,&c,&t);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&imp[i][j]);
            if(imp[i][j])
                cot++;
        }
    }
    int fst=0,lst=1000000000,mn=1000000000,fu=0;
    while(fst<=lst)
    {
        fu=0;
        memset(state,0,sizeof state);
        memset(ha,0,sizeof ha);
        memset(hb,0,sizeof hb);
        mid=(fst+lst)/2;
        num=1;
        printf("%d\n",mid);
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(state[i][j])
                    continue;
                dfs(i,j);
                num++;
            }
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(imp[i][j])
                    ha[state[i][j]]++;
                hb[state[i][j]]++;
            }
        }
        for(i=1;i<=r*c;i++)
        {
            if(hb[i]>=t&&ha[i]==cot)
            {
                fu=1;
            }
        }
        if(fu==1)
        {
            mn=min(mn,mid);
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    printf("%d",mn);
}
