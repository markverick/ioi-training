#include<bits/stdc++.h>
using namespace std;
char s[100135],t[100135];
int pi[100135];
int main()
{
    int n,i,j,k,len,T,cot;
    scanf("%d",&T);
    while(T--)
    {
        cot=0;
        scanf("%s %s",s+1,t+1);
        len=strlen(s+1);
        n=strlen(t+1);
        j=0;
        pi[1]=j;
        for(i=2;i<=len;i++)
        {
            while(j>0&&s[j+1]!=s[i])
                j=pi[j];
            if(s[i]==s[j+1])
                j++;
            pi[i]=j;
        }
    //    for(i=1;i<=len;i++)
    //    {
    //        printf("%d ",pi[i]);
    //    }
        j=0;
        for(i=1;i<=n;i++)
        {
            while(j>0&&t[i]!=s[j+1])
            {
                j=pi[j];
            }
            if(t[i]==s[j+1])
            {
                j++;
            }
            if(j==len)
            {
                cot++;
                j=pi[j];
            }
        }
        printf("%d\n",cot);
    }
}

