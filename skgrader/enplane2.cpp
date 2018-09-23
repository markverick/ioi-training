#include<bits/stdc++.h>
using namespace std;

int c[1200][600];
int jum[1200][12000];
//plane town
int p[1200];
int m[1200];
int main()
{
    int a,b,n,i,j,k;
    int mn=99999999;
    scanf("%d %d %d",&a,&b,&n);
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&p[i],&m[i]);
        for(j=0;j<m[i];j++)
        {
            scanf("%d",&c[i][j]);
        }
    }
    int fu=0;
    for(i=0;i<n;i++)
    {
        fu=0;
        for(j=0;j<m[i];j++)
        {
            if(fu==0&&c[i][j]==a)
            {
                fu=1;
            }
            else if(fu==1)
            {
                //printf("F");
                if(c[i][j]==b)
                {
                    mn=min(mn,p[i]);
                    break;
                }

                jum[i][c[i][j]]=p[i];
            }
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<=10;j++)
        {
            printf("%d ",jum[i][j]);
        }
        printf("\n");
    }*/
    //int mn=99999999;
    for(i=0;i<n;i++)
    {
        fu=0;
        for(j=m[i]-1;j>=0;j--)
        {
            if(fu==0&&c[i][j]==b)
            {
                fu=1;
            }
            else if(fu==1)
            {
                for(k=0;k<n;k++)
                {
                    if(i==k)
                        continue;
                    if(c[i][j]==a)
                        break;
                    if(jum[k][c[i][j]]!=0&&jum[k][c[i][j]]+p[i]<mn)
                        mn=jum[k][c[i][j]]+p[i];

                }

            }
        }
    }
    if(mn==99999999)
        printf("-1");
    else
        printf("%d",mn);
}
