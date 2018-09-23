#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
int r,c;
long long maps[120][120];
long long jum[120][120];
long long dp(int x,int y)
{
    if(jum[x][y]>=0)
        return jum[x][y];
    if(x==r&&y==c)
    {
        return 1;
    }
    int i,j;
    long long sum=0;
    for(i=x+1;i<=r;i++)
    {
        for(j=y+1;j<=c;j++)
        {
            if(maps[i][j]!=maps[x][y])
                sum+=dp(i,j);
            sum%=1000000007;
        }
    }
    return jum[x][y]=sum%1000000007;
}
int main()
{
    int i,j,k;
    scanf("%d %d %*d",&r,&c);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%lld",&maps[i][j]);
        }
    }
    printf("%lld\n",dp(1,1)%1000000007);
}

