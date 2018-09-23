#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
int r,c;
char maps[20][20];
int jum[20][20];
int dp(int x,int y)
{
    if(jum[x][y]>=0)
        return jum[x][y];
    if(x==r&&y==c)
    {
        return 1;
    }
    int i,j;
    int sum=0;
    for(i=x+1;i<=r;i++)
    {
        for(j=y+1;j<=c;j++)
        {
            if(maps[i][j]!=maps[x][y])
                sum+=dp(i,j);
        }
    }
    return jum[x][y]=sum;
}
int main()
{
    int i,j,k;
    scanf("%d %d",&r,&c);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    printf("%d\n",dp(1,1));
}

