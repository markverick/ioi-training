#include<bits/stdc++.h>
using namespace std;
char maps[320][320];
int cot[320][320][12];
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&maps[i][j]);
            for(k=1;k<=10;k++)
            {
                cot[i][j][k]=cot[i][j-1][k]+cot[i-1][j][k]-cot[i-1][j-1][k];
            }
            cot[i][j][maps[i][j]]++;
        }
    }
    int q,a,b,c,d;
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d %d %d %d",&a,&b,&c,&d);
        int sum=0;
        for(j=1;j<=10;j++)
        {
            if(0< cot[c][d][j]-cot[c][b-1][j]-cot[a-1][d][j]+cot[a-1][b-1][j] )
                sum++;
        }
        printf("%d\n",sum);
    }
}
