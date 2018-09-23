#include<bits/stdc++.h>
using namespace std;
int n,k;
int maps[20][20];
int qs[20][20];
int dp(int x1,int y1,int x2,int y2,int cut)
{
    if(cut==k)
    {
        return qs[x2][y2]-qs[x1-1][y2]-qs[x2][y1-1]+qs[x1-1][y1-1];
    }
    int i,j;
    int mn=1000000000;
    for(i=x1;i<x2;i++)
    {
        mn=min(mn,max(dp(i+1,x2,y1,y2,cut+1),dp(x1,i,y1,y2,cut+1)) );
    }
    for(i=y1;i<y2;i++)
    {
        mn=min(mn,max(dp(x1,x2,i+1,y2,cut+1),dp(x1,x2,y1,i,cut+1) ) );
    }
    printf("%d\n",mn);
    return mn;
}
int main()
{
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&maps[i][j]);
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+maps[i][j];
        }
    }
    printf("%d",dp(1,1,n,n,0));
}
