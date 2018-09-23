#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[55][55];
int dx[6]={1,-1,0,0},dy[6]={0,0,1,-1};
int main()
{
    int i,j,k,r,c,T,tx,ty;
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='D')
            {
                tx=i,ty=j;

            }
        }
    }
    T=r*c;
    while(T--)
    {
//        for(i=1;i<=r;i++)
//        {
//            for(j=1;j<=c;j++)
//            {
//                printf("%c",maps[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if(maps[i][j]=='S')
                    for(k=0;k<4;k++)
                        if(maps[i+dx[k]][j+dy[k]]!='X'&&maps[i+dx[k]][j+dy[k]]!='*'&&maps[i+dx[k]][j+dy[k]]!='S')
                            maps[i+dx[k]][j+dy[k]]='s';
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if(maps[i][j]=='s')
                    maps[i][j]='S';
        if(maps[tx][ty]=='S')
        {
            printf("%d",r*c-T);
            return 0;
        }
//        for(i=1;i<=r;i++)
//        {
//            for(j=1;j<=c;j++)
//            {
//                printf("%c",maps[i][j]);
//            }
//            printf("\n");
//        }
//        printf("\n");
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                if(maps[i][j]=='*')
                {
                    for(k=0;k<4;k++)
                    {
                        if(maps[i+dx[k]][j+dy[k]]!='X'&&maps[i+dx[k]][j+dy[k]]!='D'&&maps[i+dx[k]][j+dy[k]]!='*')
                            maps[i+dx[k]][j+dy[k]]='x';
                    }
                }
            }
        }
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                if(maps[i][j]=='x')
                    maps[i][j]='*';
//        for(i=1;i<=r;i++)
//        {
//            for(j=1;j<=c;j++)
//            {
//                printf("%c",maps[i][j]);
//            }
//            printf("\n");
//        }
//        system("pause");

    }
    printf("KAKTUS");
}
