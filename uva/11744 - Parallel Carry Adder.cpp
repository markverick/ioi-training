#include<bits/stdc++.h>

char a[40],b[40],c[40];
int main()
{
    int t,T,i,j,k;
    scanf("%d",&T);
    for(t=0;t<T;t++)
    {
        int fu=0;
        scanf("%s %s",a,b);

        for(i=0;i<31;i++)
        {
            if(b[i]=='1')
            {
                fu=1;
                //break;
            }
        }
        if(fu==0)
        {
            if(t<T-1)
                printf("%s %s\n",a,b);
            else
                printf("%s %s",a,b);
            continue;
        }
        else
            printf("%s %s\n",a,b);
        while(true)
        {
            for(i=0;i<31;i++)
            {
                if(a[i]=='0'&&b[i]=='0')
                {
                    a[i]='0';
                    c[i]='0';
                }
                else if(a[i]=='0'&&b[i]=='1')
                {
                    a[i]='1';
                    c[i]='0';
                }
                else if(a[i]=='1'&&b[i]=='0')
                {
                    a[i]='1';
                    c[i]='0';
                }
                else
                {
                    c[i]='1';
                    a[i]='0';
                }
            }
            if(c[0]=='1')
            {
                //fu=1;
                //overflow
                printf("%s overflow\n",a);
                break;
            }
            //int cot=0;
            fu=0;
            b[30]='0';
            for(i=0;i<30;i++)
            {
                b[i]=c[i+1];
                if(b[i]=='1')
                {
                    fu=1;
                    //break;
                }
            }
            b[30]='0';

            if(fu==0)
            {
                printf("%s %s\n",a,b);
                break;
            }
            printf("%s %s\n",a,b);


            //system("pause");
        }
        if(t<T-1)
        printf("\n");
    }
}
