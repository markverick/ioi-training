#include<bits/stdc++.h>
using namespace std;
int seq[12000];
//int adj[120][120];
int d[120][120];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&seq[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&d[i][j]);
        }
    }
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    int sum=0;
    for(i=2;i<=m;i++)
    {
        sum+=d[seq[i-1]][seq[i]];
    }
    printf("%d",sum);

}
