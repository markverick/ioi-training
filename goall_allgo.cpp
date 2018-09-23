#include<bits/stdc++.h>
using namespace std;
int n;
char maps[60][60];
int d[60][60];
int main()
{
    int i,j,k,l;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s",maps[i]+1);
        }
        for(l=1;l<=n;l++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(maps[i][j]=='0')
                        continue;
                    for(k=1;k<=n;k++)
                    {
                        if(maps[j][k]=='1')
                            maps[i][k]='1';
                    }
                }
            }
        }
        int x=0,y=0;
        for(i=1;i<=n;i++)
        {
            int cot=0;
            for(j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                if(maps[i][j]=='1')
                    cot++;
            }
            if(cot==n-1)
                x++;
        }
        for(i=1;i<=n;i++)
        {
            int cot=0;
            for(j=1;j<=n;j++)
            {
                if(i==j)
                    continue;
                if(maps[j][i]=='1')
                    cot++;
            }
            if(cot==n-1)
                y++;
        }
        printf("%d %d\n",x,y);
    }
}
