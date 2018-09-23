#include<bits/stdc++.h>
using namespace std;
int ft[6][3135],n;
//int qs[4][3005][3005];
short qs[4][3005][3005];
char qc[4][3005][3005];
void add(int x,int val,int id)
{
    while(x<=3000)
    {
        ft[id][x]+=val;
        x+=x&-x;
    }
}
int sum(int x,int id)
{
    int sm=0;
    while(x>0)
    {
        sm+=ft[id][x];
        x-=x&-x;
    }
    return sm;
}
int quick(int id,int a,int b,int c,int d)
{
    int sm=0;
    sm+=(int)(qc[id][c][d])*30000+(int)qs[id][c][d];
    sm-=(int)(qc[id][c][b-1])*30000+(int)qs[id][c][b-1];
    sm-=(int)(qc[id][a-1][d])*30000+(int)qs[id][a-1][d];
    sm+=(int)(qc[id][a-1][b-1])*30000+(int)qs[id][a-1][b-1];
    return sm;
}
int out(int a,int b,int c,int d)
{
    int sm=sum(c-1,1)+sum(a-1,2)+n-sum(d,3)+n-sum(b,0);
    int sm2=quick(1,1,1,a-1,c-1)+quick(2,1,d+1,a-1,3000)+quick(3,b+1,d+1,3000,3000)+quick(0,b+1,1,3000,c-1);
//    printf("%d %d\n",sm,sm2);
    return sm-sm2;
}
int main()
{
    int m,i,j,k,a,b,c,d;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d %d",&a,&c,&b,&d);
        add(b,1,2);
        add(a,1,0);
        add(d,1,1);
        add(c,1,3);
        qs[1][b][d]++;if(qs[1][b][d]>=30000)qs[1][b][d]%=30000,qc[1][b][d]++;
        qs[2][b][c]++;if(qs[2][b][c]>=30000)qs[2][b][c]%=30000,qc[2][b][c]++;
        qs[3][a][c]++;if(qs[3][a][c]>=30000)qs[3][a][c]%=30000,qc[3][a][c]++;
        qs[0][a][d]++;if(qs[0][a][d]>=30000)qs[0][a][d]%=30000,qc[0][a][d]++;
    }
    int tmp;
    for(i=0;i<4;i++)
    {
        for(j=1;j<=3000;j++)
        {
            for(k=1;k<=3000;k++)
            {
                qc[i][j][k]+=qc[i][j-1][k]+qc[i][j][k-1]-qc[i][j-1][k-1];
                tmp=(int)qs[i][j-1][k]+(int)qs[i][j][k-1]-(int)qs[i][j-1][k-1]+(int)qs[i][j][k];
                while(tmp<0)
                {
                    tmp+=30000;
                    qc[i][j][k]--;
                }
                while(tmp>=30000)
                {
                    tmp-=30000;
                    qc[i][j][k]++;
                }
                qs[i][j][k]=(short)tmp;
            }
        }
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&a,&c,&b,&d);
        printf("%d\n",n-out(a,b,c,d));
    }
}
