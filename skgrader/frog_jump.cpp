#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int r,c;
int rr[500][500];
int dd[500][500];
int x[62550];
int y[62550];
int jum[500][500];
int chk[500][500];
int main()
{
    int i,j,k;
    while(scanf("%d %d",&r,&c)!=EOF)
    {
        memset(x,0,sizeof x);
        memset(y,0,sizeof y);
        memset(jum,-1,sizeof jum);
        memset(chk,0,sizeof chk);
        int fst=0,lst=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&rr[i][j]);
            }
        }
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                scanf("%d",&dd[i][j]);
            }
        }
        x[lst]=0;y[lst++]=0;
        int a,b;
        jum[0][0]=0;chk[0][0]=1;
        for(i=0;true;i++)
        {

            a=x[fst];b=y[fst];
           // printf("%d\n",jum[a][b]);
            if(chk[r-1][c-1]==1)
            {
                break;
            }
            fst++;
            if(chk[(a+dd[a][b])%r][b]==0)
            {
                jum[(a+dd[a][b])%r][b]=jum[a][b]+1;
                chk[(a+dd[a][b])%r][b]=1;
                x[lst]=(a+dd[a][b])%r;
                y[lst++]=b;
            }
            if(chk[a][(b+rr[a][b])%c]==0)
            {
                jum[a][(b+rr[a][b])%c]=jum[a][b]+1;
                chk[a][(b+rr[a][b])%c]=1;
                x[lst]=a;
                y[lst++]=(b+rr[a][b])%c;
            }

        }/*
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                printf("%d ",jum[i][j]);
            }
            printf("\n");
        }*/
        printf("%d\n",jum[r-1][c-1]);
    }


}
