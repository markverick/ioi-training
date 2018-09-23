#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int si[50],ai[50],ii[50];
char result[1148576];
char s1[3]; //1048576 //1148576
char s2[5];
char s3[9];
char s4[17];
char s5[33];
char s6[65];
char s7[129];
char s8[257];
char s9[513];
char s10[1025];
char s11[2049];
char s12[4097];
char s13[8193];
char s14[16385];
char s15[32769];
char s16[65537];
char s17[131073];
char s18[262145];
char s19[524289];
char s20[1048577];
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

        cg++;
        switch (cg)
        {
            case 1:strcpy(s1,result);break;
            case 2:strcpy(s2,result);break;
            case 3:strcpy(s3,result);break;
            case 4:strcpy(s4,result);break;
            case 5:strcpy(s5,result);break;
            case 6:strcpy(s6,result);break;
            case 7:strcpy(s7,result);break;
            case 8:strcpy(s8,result);break;
            case 9:strcpy(s9,result);break;
            case 10:strcpy(s10,result);break;
            case 11:strcpy(s11,result);break;
            case 12:strcpy(s12,result);break;
            case 13:strcpy(s13,result);break;
            case 14:strcpy(s14,result);break;
            case 15:strcpy(s15,result);break;
            case 16:strcpy(s16,result);break;
            case 17:strcpy(s17,result);break;
            case 18:strcpy(s18,result);break;
            case 19:strcpy(s19,result);break;
            case 20:strcpy(s20,result);break;
        }
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
