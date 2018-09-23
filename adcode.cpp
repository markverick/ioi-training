#include<bits/stdc++.h>
int hsh[20];
int main()
{
    int chck=0,flip=0;
    int i,j;
    int k;
    int a,d;
    int v;
    int len;
    scanf("%d",&k);
    for(i=1;true;i++)
    {
        chck=0;

        memset(hsh,0,sizeof(hsh));
        a=k*i;
        len=floor(log10(a));
       // printf("%d",len);

        if(len>=5)
        {

            if(flip==0)printf("No Arm/Disarm Code");
            break;
        }
        if(len<4)
            continue;

            //printf("KUAY");
        v=a;
        for(j=10000;j>=1;j/=10)
        {

            if(hsh[v/j]!=0)
            {

                chck=1;
                break;
            }
            hsh[v/j]=1;
            v=v%j;
        }
        if(chck==0)
        {
            flip=1;
            printf("%d %d\n",a,i);
        }
    }
}
