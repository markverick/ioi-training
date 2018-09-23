#include<bits/stdc++.h>

char s2[10000];
char s3[10000];
int d2[10000];
int d3[10000];
int main()
{
    scanf("%s %s",s2,s3);
    int l2=strlen(s2);
    int l3=strlen(s3);
    int i,j,k;
    for(i=0;i<l2;i++)
    {
        s2[i]-='0';
    }
    for(i=0;i<l3;i++)
    {
        s3[i]-='0';
    }
    char temp;
    for(i=0;i<l2;i++)
    {
        temp=s2[i];
        s2[i]=1-s2[i];
        k=1;
        int sum=0;
        for(j=l2-1;j>=0;j--)
        {
            sum+=k*s2[j];
            k*=2;
        }
        s2[i]=temp;
        d2[i]=sum;
    //printf("%d\n",sum);
    }
    for(i=0;i<l3;i++)
    {
        temp=s3[i];
        s3[i]=(s3[i]+1)%3;
        k=1;
        int sum=0;
        for(j=l3-1;j>=0;j--)
        {
            sum+=k*s3[j];
            k*=3;
        }
        s3[i]=temp;
        d3[2*i]=sum;
        //printf("%d\n",sum);
        temp=s3[i];
        s3[i]=(s3[i]+2)%3;
        k=1;
        sum=0;
        for(j=l3-1;j>=0;j--)
        {
            sum+=k*s3[j];
            k*=3;
        }
        s3[i]=temp;
        d3[2*i+1]=sum;
        //printf("%d\n",sum);
    }
    for(i=0;i<l2;i++)
    {
        for(j=0;j<2*l3;j++)
        {
            if(d2[i]==d3[j])
            {
                printf("%d",d2[i]);
                break;
            }
        }
    }
}
