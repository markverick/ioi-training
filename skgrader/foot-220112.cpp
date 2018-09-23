#include<bits/stdc++.h>
using namespace std;
int r,c,a,m;
int n;
int maps[1200][1200];
int sum[1200][1200];
int main()
{
    int temp1,temp2;
    int i,j,k;

    int t,T;
    scanf("%d",&T);

    for(t=0;t<T;t++)
    {
        memset(sum,0,sizeof sum);
        scanf("%d %d %d %d",&r,&c,&a,&m);
        for(i=1;i<=r;i++)
            for(j=1;j<=c;j++)
                maps[i][j]=1;
        //printf("%d\n",maps[0][0]);
        for(i=1;i<=m;i++)
        {
            scanf("%d %d",&temp1,&temp2);
            maps[temp1][temp2]=0;
        }
        for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                //scanf("%d",&b);
                sum[i][j]=sum[i][j-1]+maps[i][j];
            }
            for(j=1;j<=c;j++)
            {
                sum[i][j]+=sum[i-1][j];//printf("=%d\n",sum[i][j]);
            }
        }
        /*for(i=1;i<=r;i++)
        {
            for(j=1;j<=c;j++)
            {
                printf("%d ",sum[i][j]);
            }
            printf("\n");
        }*/
        int f=1;
        int hi=0;
        int aa=0;
        int fk=0;
        //sum[i][j]-sum[i-n][j]-sum[i][j-m]+sum[i-n][j-m];
        int c2=c,r2=r;
        for(i=1;i<=r;i++)
        {
            //if(i>r2+1)
            r2=r;

            for(n=i;n<=r2;n++)
            {//printf("==%d %d\n",n,r2);
                c2=c;
                for(j=1;j<=c;j++)
                {
                    if(j>c2+1)
                        c2=c;
                    for(m=j;m<=c2;m++)
                    {

                        aa=sum[n][m]-sum[n][j-1]-sum[i-1][m]+sum[i-1][j-1];
                        //printf("[%d][%d]-[%d][%d] = %d\n",i,j,n,m,aa);
                        if(aa!=(n-i+1)*(m-j+1))
                        {
                            c2=m-1;
                            //r2=n-1;
                        }
                        else
                        {
                            if(aa>=a)
                                f=0;
                        }
                    }
                }
                //printf("+=%d %d\n",n,r2);
            }
        }
        if(f==0)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }


}

