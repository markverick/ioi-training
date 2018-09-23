#include<bits/stdc++.h>
int maps[150][150];
int main()
{
    int i,j,k,x,y;
    int t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d %d",x,y);
        for(j=1;j<=x;j++)
        {
            for(k=1;k<=y;k++)
            {
                scanf("%d",maps[j][k]);
            }
        }
    }
}
