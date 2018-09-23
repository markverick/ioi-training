#include<bits/stdc++.h>
using namespace std;
char s[100135],t[100135];
int pi[100135];
int main()
{
    int n,i,j,k,len;
    scanf("%s %s",t+1,s+1);
    len=strlen(s+1);
    n=strlen(t+1);
    j=0;
    pi[1]=j;
    int p;
    for(i=2;i<=len;i++)
    {
        while(j>0&&s[j+1]!=s[i])
            j=pi[j];
        if(s[i]==s[j+1])
            j++;
        p=j;
        if(s[i]=='?')
        {
            while(p>0)
                p=pi[p];
        }
        pi[i]=p;
    }
    for(i=1;i<=len;i++)
    {
        printf("%d ",pi[i]);
    }
    printf("\n");
    j=0;
    for(i=1;i<=n;i++)
    {
        while(j>0&&t[i]!=s[j+1]&&s[j+1]!='?')
            j=pi[j];
        if(t[i]==s[j+1]||s[j+1]=='?')
            j++;
            printf("%d %d\n",i,j);
        if(j==len)
        {
            printf("%d\n",i-len);
            for(k=1;k<=len;k++)
                printf("%c",t[i-len+k]);
            printf("\n");
            j=pi[j];
        }
    }
}
