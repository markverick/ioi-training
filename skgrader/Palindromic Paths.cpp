#include<bits/stdc++.h>
using namespace std;

char maps[22][22];
char result[2222];
int n;
int cot=0;
int a[1000];
int b[1000];
int main()
{
    //freopen("palpath.in","r",stdin);
    //freopen("palpath.out","w",stdout);
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%s",maps[i]+1);
    }
    char c='A';
    int sum=1;
    for(i=1;i<n;i++)
    {
        memset(a,0,sizeof 0);
        memset(b,0,sizeof 0);
        for(j=0;j<i;j++)
        {
            a[ maps[1+j][i-j] ]++;
            b[ maps[n-i+j+1][n-j] ]++;
        }
        for(c='A';c<='Z';c++)
        {
            if(a[c]==0||b[c]==0)
                continue;
            printf("%d\n",sum);
            sum*=a[c]*b[c];
        }
        /*
        for(j=1;j<=n;j++)
        {
            for(k=1;k<=n;k++)
            {
                printf("%c",maps[j][k]);
            }
            printf("\n");
        }
        printf("=====\n");*/

    }
    printf("%d",sum);
}
