#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int si[50],ai[50],ii[50];
int sd,ad,id;
int f=0;
char result[50];
int n;
int cg=0;
void gen(int idx,int ss,int as,int is)
{
    //printf("F");
    if(f==1)
        return;
    int i;
    if(idx==n)
    {
        if(ss==sd&&as==ad&&is==id)
        {
            printf("yes\n");
            f=1;
            return;
        }
        else
        {
            return;
        }
        //printf("\n");
    }
    gen(idx+1,ss,as,is);
    gen(idx+1,ss+si[idx],as+ai[idx],is+ii[idx]);
}
int main()
{
    int t,T,i,j,k;


    //gen(0);
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
        f=0;
        scanf("%d %d %d",&sd,&ad,&id);
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&si[i],&ai[i],&ii[i]);
        }
        gen(0,0,0,0);
        if(f==0)
        {
            printf("no\n");
        }

    }
}
