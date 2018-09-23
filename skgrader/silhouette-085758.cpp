#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
char maps[1500][1500];
char out[1500][1500];
char chk[1500][1500];
int a[13000],b[13000],c[13000];
int main()
{
    int tod=0;
    int n,l=0,h=0,fst=99999999;
    scanf("%d",&n);
    int i,j,k;
    for(i=0;i<1500;i++)
        for(j=0;j<1500;j++)
        maps[i][j]='.';
    for(i=0;i<1500;i++)
        for(j=0;j<1500;j++)
        out[i][j]='.';
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&a[i],&b[i],&c[i]);
        b[i]--;
        fst=min(fst,a[i]);
        h=max(h,c[i]);
        l=max(l,b[i]);
    }
    //printf("%d %d\n",h,l);
    for(i=0;i<n;i++)
    {
        //system("pause");
        for(j=h-c[i]+1;j<=h;j++)
        {

            maps[j][a[i]]='#';//system("pause");
            maps[j][b[i]]='#';
        }
        for(j=a[i];j<b[i];j++)
        {
            maps[h-c[i]+1][j]='#';
        }
    }
    /*for(i=1;i<=l;i++)
    {
        int chck=0;
        for(j=1;j<=h;j++)
        {
            if(chck==1)
                maps[j][i]=',';
            if(maps[j][i]=='#')
            {
                chck=1;
            }
        }
    }*/
    /*
    for(i=1;i<=h;i++)
    {
        for(j=fst;j<=l;j++)
        {
            printf("%c",maps[i][j]);
        }
        printf("\n");
    }
    for(i=fst;i<=l;i++)
        printf("*");
        */
    int x=h,y=fst;
    int cot=0,tan=0;
    //printf("%d %d\n",x,y);
    //system("pause");
    int chck=0;
    while(true)
    {
        //printf("[%d][%d]\n",x,y);
        //system("pause");
        chk[x][y]=1;
        if(chck==0)
            out[x][y]='#';
        else
        {
            chck=0;
        }
        //printf("[%d][%d] = %d\n",x,y,cot);
        if(x-1>=0&&chk[x-1][y]==0&&maps[x-1][y]=='#')
        {
            cot++;  x--;    continue;
        }
        else if(chk[x][y+1]==0&&maps[x][y+1]=='#')
        {
            cot++;  y++;    continue;
        }
        else  if(chk[x+1][y]==0&&x+1<=h&&maps[x+1][y]=='#')
        {
            cot++;  x++;    continue;
        }
        else
        {
            if(x==h&&y==l)
            {
                //printf("%d\n",tan);
                break;
            }
            //printf("FFFFF\n\n");
            while(maps[x][y+1]!='#')
            {
                y++;
                tan++;
                chck=1;
            }
            tod++;
            //printf("BREAK! at [%d][%d]",x,y);
            //system("pause");
            //break;
        }

    }
    cot=0;
    for(i=1;i<=h;i++)
    {
        for(j=fst;j<=l;j++)
        {
            if(out[i][j]=='#')
                cot++;
        }
    }
    printf("%d\n",cot+tod*2);
    for(i=1;i<=h;i++)
    {
        for(j=fst;j<=l;j++)
        {
            printf("%c",out[i][j]);
        }
        printf("\n");
    }
    for(i=fst;i<=l;i++)
    {
        printf("*");
    }
}
