#include<bits/stdc++.h>
int n;
int x[30],y[30];
char maps[7][7]; //x = sold out, o = walkable

int dp(int a,int b,int c,int d,char chk[7][7])
{

    if(chk[a][b]=='x'||chk[c][d]=='x')
    {
        return 0;
    }

    if(a==c&&b==d)
    {
        return 1;
    }
    chk[a][b]='x';
    chk[c][d]='x';
    return dp(a+1,b,c+1,d,chk)+dp(a-1,b,c+1,d,chk)+dp(a,b+1,c+1,d,chk)+dp(a,b-1,c+1,d,chk)+
           dp(a+1,b,c-1,d,chk)+dp(a-1,b,c-1,d,chk)+dp(a,b+1,c-1,d,chk)+dp(a,b-1,c-1,d,chk)+
           dp(a+1,b,c,d+1,chk)+dp(a-1,b,c,d+1,chk)+dp(a,b+1,c,d+1,chk)+dp(a,b-1,c,d+1,chk)+
           dp(a+1,b,c,d-1,chk)+dp(a-1,b,c,d-1,chk)+dp(a,b+1,c,d-1,chk)+dp(a,b-1,c,d-1,chk);
}
int main()
{
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<=5;i++)
        maps[i][0]='x';
    for(j=0;j<=5;j++)
        maps[0][j]='x';
    for(i=0;i<=5;i++)
        maps[i][6]='x';
    for(j=0;j<=5;j++)
        maps[6][j]='x';
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            maps[i][j]='o';
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        maps[x[i]][y[i]]='x';
    }

    printf("%d",dp(1,1,5,5,maps));
}
