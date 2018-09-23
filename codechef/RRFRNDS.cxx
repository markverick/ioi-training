#include<bits/stdc++.h>
using namespace std;
int n,deg[2222][70];
char s[2222];
int mat[2222][2222];
int main()
{
    int i,j,k,x,len;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        memset(s,0,sizeof s);
        scanf("%s",s);
        for(j=0;j<n;j++)
        {
            if(s[j]=='1')
                mat[i][j+1]=1;
        }
        for(j=0;j<=n/30;j++)
        {
            x=0;
            for(k=0;k<30;k++)
            {
                if(s[j*30+k]=='1')
                {
                    x++;
                }
                x*=2;
            }
            deg[i][j]=x;
//            printf("%d",deg[i][j]);
        }
//        printf("\n");
    }
    int cot=0;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(mat[i][j])continue;
            for(k=0;k<=n/30;k++)
            {
                if((deg[i][k]&deg[j][k])!=0)
                {
                    cot++;
                    break;
                }
            }
        }
    }
    printf("%d",cot*2);
}
