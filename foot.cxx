#include<bits/stdc++.h>
using namespace std;
int maps[330][330];
int qs[330][330];
int main()
{
    int T,i,j,k,r,c,a,m,x,y,s;
    scanf("%d",&T);
    while(T--)
    {
        memset(maps,0,sizeof maps);
        memset(qs,0,sizeof qs);
        scanf("%d %d %d %d",&r,&c,&a,&m);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&x,&y);
            maps[x][y]=1;
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                qs[i][j]=qs[i][j-1]+qs[i-1][j]-qs[i-1][j-1]+maps[i][j];
            }
        }
        int fu=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                for(k=1;k<=r-i;k++)
                {
                    s=(a-1)/k+1;
                    if(s>c-j)
                        continue;
                    if(qs[i+k][j+s]-qs[i][j+s]-qs[i+k][j]+qs[i][j]==0)
                    {
                        fu=1;
                        break;
                    }
                }
                if(fu==1)break;
            }
            if(fu==1)break;
        }
        printf("%s\n",fu==1?"yes":"no");
    }
}
