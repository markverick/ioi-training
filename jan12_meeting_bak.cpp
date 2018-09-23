#include<bits/stdc++.h>
int n;
int x[30],y[30];
char maps[7][7]; //x = sold out, o = walkable

int dp(int a,int b,int c,int d,char chk[7][7],int cot)
{
    int i,j;
    /*
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            printf("%c ",chk[i][j]);
        }
        printf("\n");
    }
    printf("======\n");
    system("pause");*/
    if(chk[a][b]=='x'||chk[c][d]=='x')
    {
        return 0;
    }

    if(cot*2>=25-n)
    {
        printf("%d %d\n",cot*2,25-n);
        if(a==c&&b==d)
            return 1;
        else
            return 0;

    }
    printf("%d\n",cot);
    chk[a][b]='x';
    chk[c][d]='x';
    return dp(a+1,b,c+1,d,chk,cot+1)+dp(a-1,b,c+1,d,chk,cot+1)+dp(a,b+1,c+1,d,chk,cot+1)+dp(a,b-1,c+1,d,chk,cot+1)+
           dp(a+1,b,c-1,d,chk,cot+1)+dp(a-1,b,c-1,d,chk,cot+1)+dp(a,b+1,c-1,d,chk,cot+1)+dp(a,b-1,c-1,d,chk,cot+1)+
           dp(a+1,b,c,d+1,chk,cot+1)+dp(a-1,b,c,d+1,chk,cot+1)+dp(a,b+1,c,d+1,chk,cot+1)+dp(a,b-1,c,d+1,chk,cot+1)+
           dp(a+1,b,c,d-1,chk,cot+1)+dp(a-1,b,c,d-1,chk,cot+1)+dp(a,b+1,c,d-1,chk,cot+1)+dp(a,b-1,c,d-1,chk,cot+1);
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
    //maps[1][1]='x';maps[5][5]='x';
    printf("%d",dp(1,1,5,5,maps,0));
}
