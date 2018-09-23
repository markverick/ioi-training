#include<bits/stdc++.h>
int maps[600][600];
int main()
{
    int t,n,i,j,k,num=1; //num always %10
    scanf("%d",&t);
    int marginX=0,marginY=0;
    for(k=0;k<t;k++)
    {
        marginX=0;marginY=0;num=1;
        scanf("%d",&n);
        while(marginX<=n||marginY<=n)
        {
            for(i=marginX;i<n;i++)
            {
                maps[i][marginY]=num%10;
                num++;
            }
            for(i=n-1;i>=marginX;i--)
            {
                maps[i][marginY+1]=num%10;
                num++;
            }
            marginY+=2;
            for(j=marginY;j<n;j++)
            {
                maps[marginX][j]=num%10;
                num++;
            }
            for(j=n-1;j>=marginY;j--)
            {
                maps[marginX+1][j]=num%10;
                num++;
            }
            marginX+=2;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d ",maps[j][i]);
            }
            printf("\n");
        }

    }
}
