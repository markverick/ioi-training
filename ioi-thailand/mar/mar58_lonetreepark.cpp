#include<bits/stdc++.h>
using namespace std;

char maps[35][35];
int sum[35][35];

int main()
{
    int T,t,i,j,k;
    int r,c;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        scanf("%d %d",&r,&c);
        for(i=1;i<=r;i++)
        {
            scanf("%s",maps[i]+1);
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(maps[i][j]=='.')
                    maps[i][j]=0;
                if(maps[i][j]=='#')
                    maps[i][j]=1;
            }
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+maps[i][j];
            }
        }/*
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                printf("%d ",sum[i][j]);
            }
            printf("\n");
        }*/
        int yolo=0;
        for(k=0;k<=min(c,r);k++) //k must +1
        {
            yolo=0;
            for(i=1;i<=r-k;i++)
            {
                for(j=1;j<=c-k;j++)
                {
                    if(sum[i+k][j+k]-sum[i-1][j+k]-sum[i+k][j-1]+sum[i-1][j-1]==1)
                    {
                        yolo=1;
                        break;
                    }
                }
                if(yolo==1)
                    break;
            }
            if(yolo==0)
                break;
        }
        printf("%d\n",k);
    }
}
