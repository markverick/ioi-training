#include<bits/stdc++.h>
using namespace std;
char maps[222][222];
int qs[222][222],r,c,i,j,k,l,area=0;
int quicksum(int a,int b,int c,int d)
{
    return qs[c][d]-qs[c][b-1]-qs[a-1][d]+qs[a-1][b-1];
}
int main()
{
    scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='X')
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+maps[i][j];
            else
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];
        }
    }
    for(i=1;i<=r;i++)
        for(j=1;j<=c;j++)
            for(k=0;i+k<=r;k++)
            {
                if(maps[i+k][j]!='.')
                    break;
                for(l=area/(k+1);j+l<=c;l++)
                {
                    if(maps[i][j+l]!='.')
                        break;
                    if(quicksum(i+k,j,i+k,j+l)==0&&quicksum(i,j+l,i+k,j+l)==0&&quicksum(i,j,i+k,j)==0&&quicksum(i,j+l,i,j)==0)
                        area=max(area,(k+1)*(l+1));
                }
            }
    printf("%d",area);
}
