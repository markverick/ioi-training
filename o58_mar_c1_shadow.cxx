#include<bits/stdc++.h>
using namespace std;
int maps[2135][2135],C[2135],D[2135],n;
int jum[2135][2135][3];
int dp(int x,int y,int dir)
{
    if(jum[x][y][dir]>=0)
        return jum[x][y][dir];
    if(x>n)
        return 1000000000;
//    printf("%d %d %d",x,y,dir);
    if(y==n&&x==n)
    {
        if(x==n)
            return 0;
        else
            return 1000000000;
    }
    if(dir==0)
    {
        if(x+y+1>=n+1)
        {
            if(y<n)
                return jum[x][y][dir]=min(dp(x+1,y,0),dp(x,y+1,1-maps[x][y+1])+D[y+1]);
            else
                return jum[x][y][dir]=dp(x+1,y,0);
        }
        else
        {
            if(y<n)
            {
                return jum[x][y][dir]=min(dp(x+1,y,0),dp(x,y+1,1-maps[x][y+1])+C[y+1]);
            }
            else
                return jum[x][y][dir]=dp(x+1,y,0);
        }
    }
    else if(y<n)
    {
        if(x+y+1>=n+1)
        {
            return jum[x][y][dir]=dp(x,y+1,1-maps[x][y+1])+D[y+1];
        }
        else
        {
            return jum[x][y][dir]=dp(x,y+1,1-maps[x][y+1])+C[y+1];
        }
    }
    return jum[x][y][dir]=1000000000;
}
int main()
{
    memset(jum,-1,sizeof jum);
    int m,i,j,k,a,b;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&C[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&D[i]);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        a++;b++;
        maps[a][b]=1;
    }
    printf("%d\n",dp(1,1,0));
}
