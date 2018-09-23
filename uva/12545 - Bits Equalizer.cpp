#include<bits/stdc++.h>
using namespace std;
char a[120];
char b[120];
void swp(char *p,char *q)
{
    char temp = *p;
    *p = *q;
    *q = temp;
}
int main()
{
    int c,d; //number of one
    int T,t,i,j,k;
    int sum=0;
    scanf("%d",&T);
    int chk=0;
    for(t=0;t<T;t++)
    {
        sum=0;c=0;d=0;
        int fu=0;
        scanf("%s %s",a,b);
        int len=strlen(a);
        for(i=0;i<len;i++)
        {
            chk=0;
            if(a[i]=='1'&&b[i]=='0')
            {
                for(j=i+1;j<len;j++)
                {
                    if(a[j]=='0'&&b[j]=='1')
                    {
                        //printf("FFFFF");
                        swp(&a[i],&a[j]);
                        sum++;
                        break;
                    }

                }
            }
            else if(a[i]=='0'&&b[i]=='1')
            {
                for(j=i+1;j<len;j++)
                {
                    if(a[j]=='1'&&b[j]=='0')
                    {
                        swp(&a[i],&a[j]);
                        sum++;
                        break;
                    }
                }
            }
            //printf("%d\n",sum);
        }
        if(strcmp(a,b)==0)
        {
            printf("Case %d: %d\n",t+1,sum);
            continue;
        }
        //printf("SUM = %d\n",sum);
        //printf(">%s\n %s\n",a,b);
        chk=0;
        c=0;d=0;int e=0;

        for(i=0;i<len;i++)
        {
            if(a[i]=='1')
                c++;
            if(a[i]!='?'&&b[i]=='1')
                d++;
            if(b[i]=='1')
                e++;
        }
        //printf("-> %d %d %d",c,d,e);
        if(c>e)
        {
            printf("Case %d: -1\n",t+1);
            continue;
        }
        //printf("%d %d\n",c,d);
        for(i=0;i<len;i++)
        {
            if(a[i]=='?'&&b[i]=='1')
            {
                for(j=0;j<len;j++)
                {
                    if(a[j]=='1'&&b[j]=='0')
                    {
                        swp(&a[i],&a[j]);
                        sum++;
                        c++;
                        break;
                    }
                }//printf(" %s\n",a);
            }

            /*if(d>=c)
            {
                //system("pause");
                break;
            }*/
        }

        /*if(d>c)
        {
            printf("Case %d: -1\n",t+1);
            continue;
        }*/
        //printf("SUM = %d\n",sum);
        //printf(">%s\n %s",a,b);
        for(i=0;i<len;i++)
        {
            if(a[i]=='?')
                sum++;
            if(a[i]=='0'&&b[i]=='1')
            {
                a[i]='1';
                sum++;
            }
        }
        printf("Case %d: %d\n",t+1,sum);
        /*if(fu==1)
        {
            printf("Case %d: -1\n",t+1);
        }
        else
        {
            printf("Case %d: %d\n",t+1,sum);
        }*/
    }
}
