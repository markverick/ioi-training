#include<bits/stdc++.h>
using namespace std;
char maps[60][60];
pair<int,int> out[60];
int main()
{
    int r,c;
    scanf("%d %d",&r,&c);
    int i,j,k;
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=0;i<=r+1;i++)
    {
        maps[i][0]='#';
        maps[i][c+1]='#';
    }
    for(i=0;i<=c+1;i++)
    {
        maps[0][i]='#';
        maps[r+1][i]='#';
    }
    /*for(i=0;i<=r+1;i++)
    {
        for(j=0;j<=c+1;j++)
        {
            printf("%c",maps[i][j]);
        }
        printf("\n");
    }*/
    //system("pause");
    for(i=0;i<=r;i++)
    {
        for(j=0;j<=c;j++)
        {
            if(maps[i][j]=='#')
            {
                for(k=i+1;k<=r;k++)
                {
                    if(maps[k][j]=='#')
                        break;
                }
                if(k-i>3)
                {
                    maps[i+1][j]='!';
                }
                for(k=j+1;k<=c;k++)
                {
                    if(maps[i][k]=='#')
                        break;
                }
                if(k-j>3)
                {
                    maps[i][j+1]='!';
                }
            }
        }
    }
    int idx=0;
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='!')
            {
                out[idx++]=make_pair(i,j);
                //printf("%d %d\n",i,j);
            }
        }
    }
    printf("%d\n",idx);
    for(i=0;i<idx;i++)
    {
        printf("%d %d\n",out[i].first,out[i].second);
    }
}
