#include<bits/stdc++.h>
using namespace std;
char s[55];
int vol[30];
int main()
{
    int T,i,j,k,len,a,b,c,d;
    vol['a'-'a']=1;
    vol['e'-'a']=1;
    vol['i'-'a']=1;
    vol['o'-'a']=1;
    vol['u'-'a']=1;
    vol['y'-'a']=1;
    scanf("%d",&T);
    while(T--)
    {
        a=0;b=0;d=0;c=0;
        scanf("%s",&s);
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(vol[s[i]-'a'])
            {
                a++;
            }
            else
            {
                b++;
            }
        }
        c=0;
        for(i=0;i<len;i++)
        {
            if(vol[s[i]-'a']==0)
            {
                c++;
            }
            else
            {
                c=0;
            }
            if(c>=3)
            {
                d=1;
            }
        }
//        printf("%d %d %d\n",a,b,d);
        if(d==1||b>a)
        {
            printf("hard\n");
        }
        else
        {
            printf("easy\n");
        }
    }
}
