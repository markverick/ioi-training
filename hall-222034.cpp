#include<bits/stdc++.h>
using namespace std;
int a,b,c;
long long x[20][20];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j,k;
    int a,b,c;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            x[i][j]=2000000000;
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d",&a,&b,&c);
        x[a][b]=c;
        x[b][a]=c;
    }
    for(i=1;i<=n;i++)
    {
        x[i][i]=0;
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                x[i][j]=min(x[i][j],x[i][k]+x[k][j]);
            }
        }
    }
    printf("%lld",(x[1][n]-1)/5+1);
}
