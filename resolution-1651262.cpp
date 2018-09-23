#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int si[50],ai[50],ii[50];
char result[50];
char sto[5000][21]; //1048576 //1148576
int n;
int cg=0;
int pow(int t)
{
    int temp=1;
    for(int i=0;i<t;i++)
    {
        temp*=2;
    }
    return temp;
}
void gen(int idx)
{
    int i;
    if(idx==20)
    {
        strcpy(sto[cg],result);
        cg++;
        /*for(i=0;i<20;i++)
        {
            printf("%d",result[i]);
        }
        printf("\n");*/

        return;
    }
    result[idx]='0';
    gen(idx+1);
    result[idx]='1';
    gen(idx+1);
}
int main()
{
    int t,T,i,j,k;
    int sd,ad,id;
    int ss,as,is;
    gen(0);
    int x=0;

    /*
    for(i=0;i<pow(x);i++)
    {
        for(j=20-x;j<20;j++)
        {
            printf("%c",sto[i][j]);
        }
        printf("\n");
    }
    */
    scanf("%d",&T);

    for(t=0;t<T;t++)
    {
        scanf("%d %d %d",&sd,&ad,&id);
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&si[i],&ai[i],&ii[i]);
        }

        x=pow(n);
        int pass=0;
        for(i=0;i<x;i++)
        {
            if(pass==1)break;
            ss=0;as=0;is=0;
            for(j=20-n;j<20;j++)
            {
                if(sto[i][j]=='1')
                {
                    //printf("F");
                    ss+=si[20-j-1];as+=ai[20-j-1];is+=ii[20-j-1];
                }
            }
            //printf("=%d %d %d\n",ss,as,is);
            if(ss==sd&&as==ad&&is==id)
            {
                printf("yes\n");
                pass=1;
                break;
            }
        }
        if(pass==0)
            printf("no\n");
    }
}
