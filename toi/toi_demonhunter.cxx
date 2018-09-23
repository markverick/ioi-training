#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int x[15];
int main()
{
    int n,m,i,j,k,Min,Max;
    scanf("%d %d",&n,&m);
    Min=min(n,m);
    Max=max(n,m);
    for(i=1;i<=Max;i++)
        x[i]=i;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int mc=0,sum=0;
    do
    {
        sum=0;
        for(i=1;i<=Min;i++)
        {
            sum+=a[i][x[i]];
        }
        mc=max(mc,sum);sum=0;
        for(i=1;i<=Min;i++)
        {
            sum+=a[x[i]][i];
        }
        mc=max(mc,sum);
    }
    while(next_permutation(&x[1],&x[Max+1]));
    printf("%d",mc);
}
