#include<bits/stdc++.h>
using namespace std;
int maps[550][550];
int sum[550][550];
int r,c;
int main()
{
    int i,j,k;

    int t,T=2;
    while(T--)
    {
        scanf("%d %d",&r,&c);
        scanf("%d",&t);
        for(i=0;i<t;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            a++;b++;
            maps[a][b]=1;
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+maps[i][j];
            }
        }
        int fu=0;
        int s;
        for(s=min(r,c)-1;s>=1;s--)
        {
            for(i=1;i<=r-s;i++)
            {
                for(j=1;j<=c-s;j++)
                {
                    if(sum[i][j+s]-sum[i][j-1]-sum[i-1][j+s]+sum[i-1][j-1]
                    + sum[i+s][j+s]-sum[i+s][j-1]-sum[i+s-1][j+s]+sum[i+s-1][j-1]
                    + sum[i+s][j]-sum[i+s][j-1]-sum[i-1][j]+sum[i-1][j-1]
                    + sum[i+s][j+s]-sum[i+s][j+s-1]-sum[i-1][j+s]+sum[i-1][j+s-1]==0)
                    {
                        fu=1;break;
                    }
                }
                if(fu==1)break;
            }
            if(fu==1)break;
        }
        if(fu==1)
        {
            printf("%d\n",s+1);
        }
        else
        {
            printf("1\n");
        }
        if(T==1)
            memset(maps,0,sizeof maps);
    }
}
