#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,maps[1135][1135],jum[1135][1135];
int dp(int x,int y)
{
    if(jum[x][y]>=0)
        return jum[x][y];
    if(x==a&&y==b)
    {
        return 1;
    }
    int sum=0;
    if(maps[x+1][y])
        sum+=dp(x+1,y);
    if(maps[x][y+1])
        sum+=dp(x,y+1);
    sum%=1000000007;
    return jum[x][y]=sum;
}
int main()
{
    int n,i,j,k;
    memset(jum,-1,sizeof jum);
    scanf("%d %d %d %d",&a,&b,&c,&d);
    for(i=0;i<=a;i++)
    {
        for(j=0;j<=b;j++)
        {
            maps[i][j]=1;
        }
    }
    for(i=a-c+1;i<=a;i++)
    {
        for(j=0;j<d;j++)
        {
            maps[i][j]=0;
        }
    }
//    for(i=0;i<=a;i++)
//    {
//        for(j=0;j<=b;j++)
//        {
//            printf("%d ",maps[i][j]);
//        }
//        printf("\n");
//    }
    printf("%d\n",dp(0,0));
}
