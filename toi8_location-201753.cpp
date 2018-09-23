#include<bits/stdc++.h>
using namespace std;
int r,c;
int n;
int sum[1200][1200];
int main()
{
    int i,j,k;
    int b;
    scanf("%d %d %d",&r,&c,&n);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            scanf("%d",&b);
            sum[i][j]=sum[i][j-1]+b;
        }
        for(j=1;j<=c;j++)
        {
            sum[i][j]+=sum[i-1][j];//printf("=%d\n",sum[i][j]);
        }

    }
    int hi=0;
    int a=0;
    for(i=r;i>=n;i--)
    {
        for(j=c;j>=n;j--)
        {
            a=sum[i][j]-sum[i-n][j]-sum[i][j-n]+sum[i-n][j-n];
            hi=max(a,hi);
            //printf("%d ",sum[i][j]);
        }
    }
    printf("%d",hi);

}
