#include<bits/stdc++.h>
using namespace std;
map<char,char> rule;
char str[1200000];
int main()
{
    int T,i,j,k;
    scanf("%d",&T);
    while(T--)
    {
        rule.clear();
        int n;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            char a[3],b[3];
            scanf("%s %s",a,b);
            rule[a[0]]=b[0];
        }
        scanf("%s",str);
        int len=strlen(str);
        for(i=0;i<len;i++)
        {
            if(rule[str[i]]!=0)
                str[i]=rule[str[i]];
        }
        int fu=0;
        for(i=0;i<len;i++)
        {
            if(fu==0&&str[i]!='0')
            {
                fu=i;
                break;
            }
        }
        int dot=-1;
        for(i=0;i<len;i++)
        {
            if(str[i]=='.')
                dot=i;
        }
        int fk=0;
        for(i=len-1;i>=0;i--)
        {
            if(dot==-1||i==dot||str[i]!='0')
            {
                fk=i;
                //printf("==%c\n",str[i]);
                break;
            }
        }
        int fkk=0;
        for(i=0;i<len;i++)
            if(str[i]!='0'&&str[i]!='.')
                fkk=1;
        if(fkk==0)
            printf("0\n");
        else
        for(i=fu;i<=fk;i++)
        {
            if(i==fk&&str[i]=='.')
                break;
            printf("%c",str[i]);
        }

        printf("\n");
    }
}
