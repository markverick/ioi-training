#include<bits/stdc++.h>
char in[2000],in2[2000],out[2000];
int main()
{
    int len=0;
    int i,j,k;
    scanf("%s",in);
    len=strlen(in);
    for(i=0;i<len;i++)
    {
        in[i]-='0';
    }
    for(i=0;i<len;i++)
    {
        in2[i+4]=in[i];
    }
    /*
    printf(" ");
    for(i=0;i<=len+3;i++)
    {
        printf("%d",in[i]);
    }
    printf("\n ");
    for(i=0;i<=len+3;i++)
    {
        printf("%d",in2[i]);
    }
    printf("\n");*/
    for(i=len+3;i>=0;i--)
    {
        out[i+1]=in[i]+in2[i]+out[i+1];
        //printf("%d",out[i+1]);
        if(out[i+1]==2)
        {
            out[i+1]=0;
            out[i]=1;
        }
        else if(out[i+1]==3)
        {
            out[i+1]=1;
            out[i]=1;
        }

    }
    //system("pause");
    for(i=0;i<=len+4;i++)
    {
        if(i==0&&out[i]==0)continue;
        printf("%d",out[i]);
    }

}
