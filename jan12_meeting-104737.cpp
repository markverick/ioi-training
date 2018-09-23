#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
int n;
int x[30],y[30];
vector<vector<char> > maps; //x = sold out, o = walkable
int dp(int a,int b,int c,int d,vector<vector<char> > chk,int cot)
{
    if(chk[a][b]=='x'||chk[c][d]=='x')
    {
        return 0;
    }

    //system("pause");
    chk[a][b]='x';
    chk[c][d]='x';
    //printf("[%d][%d] [%d][%d]\n",a,b,c,d);
    /*int i,j;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            printf("%c",chk[i][j]);
        }
        printf("\n");

    }*/
    if(a==c&&b==d)
    {

        //printf("%d\n",cot);
        if(cot*2>=24-n)
            return 1;
        else
            return 0;
    }
    int sum=0;
    return dp(a+1,b,c+1,d,chk,cot+1)+dp(a-1,b,c+1,d,chk,cot+1)+dp(a,b+1,c+1,d,chk,cot+1)+dp(a,b-1,c+1,d,chk,cot+1)+
           dp(a+1,b,c-1,d,chk,cot+1)+dp(a-1,b,c-1,d,chk,cot+1)+dp(a,b+1,c-1,d,chk,cot+1)+dp(a,b-1,c-1,d,chk,cot+1)+
           dp(a+1,b,c,d+1,chk,cot+1)+dp(a-1,b,c,d+1,chk,cot+1)+dp(a,b+1,c,d+1,chk,cot+1)+dp(a,b-1,c,d+1,chk,cot+1)+
           dp(a+1,b,c,d-1,chk,cot+1)+dp(a-1,b,c,d-1,chk,cot+1)+dp(a,b+1,c,d-1,chk,cot+1)+dp(a,b-1,c,d-1,chk,cot+1);
}
int main()
{
    scanf("%d",&n);
    int i,j,k;
    maps.resize(8);
    maps[0].resize(8);
    for(j=0;j<=6;j++)
        maps[0][j]='x';
    for(i=1;i<=5;i++)
    {
        maps[i].resize(8);
        maps[i][0]='x';
        for(j=1;j<=5;j++)
        {
            maps[i][j]='o';
        }
        maps[i][6]='x';
    }
    maps[6].resize(8);
    for(j=0;j<=6;j++)
        maps[6][j]='x';
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        maps[x[i]][y[i]]='x';
        //printf("%c",maps[x[i],y[i]]);
    }
    /*
    for(i=0;i<=6;i++)
    {
        for(j=0;j<=6;j++)
        {
            printf("%c",maps[i][j]);
        }
        printf("\n");
    }*/
    //system("pause");
    printf("%d",dp(1,1,5,5,maps,0));
}
