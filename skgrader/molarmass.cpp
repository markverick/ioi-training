#include<bits/stdc++.h>

char str[120];
double sum=0;
int main()
{
    int T,t,i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        scanf("%s",str);
        sum=0;
        int len=strlen(str);
        for(i=0;i<len;i++)
        {
            int val=0,luk=0;
            if(str[i]=='C')
            {
                for(j=i+1;j<len;j++)
                {
                    if(str[j]<'0'||str[j]>'9')
                        break;
                    val=val*10+str[j]-'0';
                }
                if(val==0)val=1;
                sum+=val*12.01;
                i=j-1;
            }
            if(str[i]=='H')
            {
                for(j=i+1;j<len;j++)
                {
                    if(str[j]<'0'||str[j]>'9')
                        break;
                    val=val*10+str[j]-'0';
                }
                if(val==0)val=1;
                sum+=val*1.008;
                i=j-1;
            }
            if(str[i]=='O')
            {
                for(j=i+1;j<len;j++)
                {
                    if(str[j]<'0'||str[j]>'9')
                        break;
                    val=val*10+str[j]-'0';
                }
                if(val==0)val=1;
                sum+=val*16.00;
                i=j-1;
            }
            if(str[i]=='N')
            {
                for(j=i+1;j<len;j++)
                {
                    if(str[j]<'0'||str[j]>'9')
                        break;
                    val=val*10+str[j]-'0';
                }
                if(val==0)val=1;
                sum+=val*14.01;
                i=j-1;
            }
            if(val==0)val=1;
            //printf("%d\n",val);
        }
        printf("%.3lf\n",sum);
    }
}
