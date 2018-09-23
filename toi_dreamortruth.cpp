#include<bits/stdc++.h>
int a[1000],c[1000],b[1000],d[1000];
int todN[1000];
char tod[1000][1000];
char aIn[1000],bIn[1000],cIn[1000];
int main()
{
    int i,j,k;
    int lenA,lenB,lenC;
    int len=0;

    scanf("%s %s %s",aIn,bIn,cIn);

    lenA=strlen(aIn);
    lenB=strlen(bIn);
    lenC=strlen(cIn);
    if(len<lenA)len=lenA;
    if(len<lenB)len=lenB;
    //if(len<lenC)len=lenC;
    for(i=0;i<=len;i++)
    {
        a[i]=0;
        b[i]=0;
        c[i]=0;
    }

    for(i=1;i<=len;i++)
    {
        if(i>len-lenA)
            a[i]=aIn[i-len+lenA-1]-'0';
        if(i>len-lenB)
            b[i]=bIn[i-len+lenB-1]-'0';

    }
    /*for(i=0;i<=len;i++)
        printf("%d",a[i]);
        printf("\n");
    for(i=0;i<=len;i++)
        printf("%d",b[i]);
        */
    memset(tod,'0',sizeof tod);
    for(i=1;i<=lenB;i++)
    {
        memset(todN,0,sizeof todN);
        for(j=len+1;j>=0;j--)
        {
            tod[i][j]=(a[j]*b[i]+todN[j])%10;
            todN[j-1]=(a[j]*b[i]+todN[j])/10;
        }
        for(j=1;j<=lenB;j++)
        {
            printf("%d",tod[i][j]);
        }
        printf("\n");

    }//addition state
    for(i=lenB;i>=0;i--)
    {

    }

    //printf("%s\n%s\n%s",a,b,c);
}
