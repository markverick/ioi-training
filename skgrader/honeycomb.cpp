#include<bits/stdc++.h>
using namespace std;
int n;
int ex[8]={0,0,1,1,-1,-1};
int ey[8]={1,-1,0,-1,0,-1};
int ox[8]={0,0,1,1,-1,-1};
int oy[8]={1,-1,0,1,0,1};
long long jum[55][55][20];
long long dp(int x,int y,int k)
{
    if(jum[x][y][k]>=0)
        return jum[x][y][k];
    if(k==n)
    {
        if(x==25&&y==25)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int i,j;
    long long sum=0;
    if(x%2==0)
    {
        for(i=0;i<6;i++)
        {
            sum+=dp(x+ex[i],y+ey[i],k+1);
        }
    }
    else
    {
        for(i=0;i<6;i++)
        {
            sum+=dp(x+ox[i],y+oy[i],k+1);
        }
    }
    return jum[x][y][k]=sum;

}
int main()
{
    scanf("%d",&n);
    memset(jum,-1,sizeof jum);
    printf("%lld\n",dp(25,25,0));
}
