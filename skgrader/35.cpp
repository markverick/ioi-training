#include<bits/stdc++.h>
char str[120000];
int main()
{
    int n,t,T;
    scanf("%d",&T);
    int i,j,k;
    while(T--)
    {
        scanf("%s",str);
        int fu=0;
        int len=strlen(str);
        int cot=0;
        for(i=0;i<=len/2;i++)
        {
            fu=0;
            if(str[i]==str[len-1-i])
                cot++;
            if(1/*str[i]!=str[len-1-i]*/)
            {
                if(str[i+1]==str[len-1-i])
                {
                    for(j=1;i+1+j+1<=len-1-i-j;j++)
                    {
                        //printf("F");
                        if(str[i+1+j]!=str[len-1-i-j])
                        {
                            fu=1;
                            break;
                        }
                    }
                    if(fu==0)
                    {
                        fu=2;
                        break;
                    }

                }
                if(str[i]==str[len-1-i-1])
                {
                    for(j=1;i+j+1<=len-2-i-j;j++)
                    {
                        if(str[i+j]!=str[len-2-i-j])
                        {
                            fu=1;
                            break;
                        }
                    }
                    if(fu==0)
                    {
                        fu=2;
                        break;
                    }

                }
            }
            if(fu==2)
            {
                fu=3;break;
            }

        }
        if(fu==3||fu==2||cot==len/2+1)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
