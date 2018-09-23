#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<map>
using namespace std;
char str[100000];
map<int,int> a;
map<int,int> b;
map<int,int> c;
map<int,int> d;
//index = m
int n,m;
int main()
{
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(k=0;k<n*m;k++)
    {
        //system("pause");
        scanf("%s",str);
        int len=strlen(str);
        int m;
        for(i=0;i<len;i++)
        {

            if(str[i]=='[')
            {
                int l=0;
                for(j=i+1;str[j]!=']';j++){
                    l++;
                }
                int num=0;
                int pow=1;
                for(j=i+l;j>=i+1;j--)
                {
                    num+=pow*(str[j]-'0');
                    pow*=10;
                }
                i=i+l;
                m=num;
                //printf("%d\n",num);system("pause");
                //printf("%d\n",l);
                //system("pause");
            }
            if(str[i]=='<')
            {
                int mi=0;
                int l=0;
                for(j=i+1;str[j]!=',';j++){
                    l++;
                }
                int num=0;
                int pow=1;
                for(j=i+l;j>=i+1;j--)
                {
                    if(str[j]=='-')
                    {
                        mi=1;
                        break;
                    }

                    num+=pow*(str[j]-'0');
                    pow*=10;
                }
                a[m]=mi==0?num:-num;
                //printf("%d",a[m]);system("pause");
                i=i+l+1;
                l=0;
                //printf("%c",str[i+1]);system("pause");
                for(j=i+1;str[j]!=',';j++){
                    l++;
                }
                mi=0;
                num=0;
                pow=1;
                for(j=i+l;j>=i+1;j--)
                {
                    if(str[j]=='-')
                    {
                        mi=1;
                        break;
                    }
                    num+=pow*(str[j]-'0');
                    pow*=10;
                }
                b[m]=mi==0?num:-num;
                //printf("%d",b[m]);system("pause");
                i=i+l+1;
                l=0;
                //printf("%c",str[i+1]);system("pause");
                for(j=i+1;str[j]!=',';j++){
                    l++;
                }
                mi=0;
                num=0;
                pow=1;
                for(j=i+l;j>=i+1;j--)
                {
                    if(str[j]=='-')
                    {
                        mi=1;
                        break;
                    }
                    num+=pow*(str[j]-'0');
                    pow*=10;
                }
                c[m]=mi==0?num:-num;
                //printf("%d",c[m]);system("pause");
                i=i+l+1;
                l=0;
                //printf("%c",str[i+1]);system("pause");
                for(j=i+1;str[j]!='>';j++){
                    l++;
                }
                mi=0;
                num=0;
                pow=1;
                for(j=i+l;j>=i+1;j--)
                {
                    if(str[j]=='-')
                    {
                        mi=1;
                        break;
                    }
                    num+=pow*(str[j]-'0');
                    pow*=10;
                }
                d[m]=mi==0?num:-num;
                i=i+l;
                //printf("%d",d[m]);system("pause");
            }
        }
    }
    int in;
    int t;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&in);
        if(c[in]-a[in]!=a[in]-d[in])
        {
            printf("a %d\n",c[in]-b[in]);
        }
        if(c[in]-b[in]!=b[in]+d[in])
        {
            printf("b %d\n",c[in]-a[in]);
        }
    }
}

/*
3 3
[3]<1,2,4,0>[7]<1,1,1,1>[31]<3,2,4,0>
[2]<9,6,16,2>[25]<0,0,-1,1>[17]<3,3,5,1>
[1]<9,5,5,-5>[9]<3,7,15,1>[6]<6,4,8,0>
3
17
31
1
*/
