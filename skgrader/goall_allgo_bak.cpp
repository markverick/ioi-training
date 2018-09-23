#include<bits/stdc++.h>
using namespace std;
int n;
char maps[60][60];
int d[60][60];
int main()
{
    int i,j,k;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s",maps[i]+1);
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(maps[i][j]=='0')
                    d[i][j]=1;
            }
            d[i][i]=0;
        }
        int l;
        for(i=1;i<=n;i++)
        {
            for(l=1;l<=n;l++)
            {
                for(j=1;j<=n;j++)
                {
                    d[l][j]=1;
                }
                d[l][i]=0;
            }
            for(j=1;j<=n;j++)
                for(k=1;k<=n;k++)
                    d[i][k]=min(d[i][k],min(d[i][j],d[j][k]));
            for(l=1;l<=n;l++)
            {
                for(j=1;j<=n;j++)
                {
                    printf("%d ",d[l][j]);
                }
                printf("\n");
            }
        }


    }
}
