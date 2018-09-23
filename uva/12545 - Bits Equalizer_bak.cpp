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
            if(a[i]=='1')
                c++;
            if(b[i]=='1')
                d++;
        }
        for(i=0;i<len;i++)
        {
            chk=0;
            if(a[i]!='?'&&a[i]!=b[i])
            {
                for(j=i+1;j<len;j++)
                {
                    if(a[j]!='?'&&a[j]!=b[j]&&a[i]!=a[j])
                    {
                        swp(&a[i],&a[j]);
                        sum++;
                        chk=1;
                        break;

                    }
                }
                if(chk==1)continue;
                if(a[i]=='0'&&b[i]==1)
                {
                    a[i]=1;c++;
                    sum++;chk=1;
                }
                if(chk==1)continue;
                for(j=i+1;j<len;j++)
                {
                    if(a[j]=='?')
                    {
                        a[j]=b[j];
                        sum+=2;
                        if(b[i]==1)
                            c++;
                        chk=1;
                    }
                }
                if(chk==1)continue;
                fu=1;break;
            }
            else
            {
                if(a[i]=='?')
                {
                    if(c<d)
                    {
                        sum++;
                        if(b[i]=='1')
                            c++;
                        a[i]=b[i];
                        chk=1;
                    }
                    else
                    {
                        for(j=i+1;j<len;j++)
                        {
                            if(a[j]=='0')
                            {
                                a[i]='0';sum+=2;
                                swp(&a[i],&a[j]);
                                chk=1;
                            }
                            else if(a[j]=='1'&&b[i]=='1')
                            {
                                a[i]='0';
                                swp(&a[i],&a[j]);
                                sum+=2;chk=1;
                            }
                        }

                    }
                    if(chk==1)continue;
                    printf("CHCKKK");
                    fu=1;break;
                }
            }
        }
        if(fu==1)
        {
            printf("Case %d: -1\n",t+1);
        }
        else
        {
            printf("Case %d: %d\n",t+1,sum);
        }
    }
}
