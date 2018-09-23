#include<bits/stdc++.h>
using namespace std;
char s[1000135];
int pi[1000135];
int main()
{
    int i,j,k,len;
    scanf("%s",s+1);
    len=strlen(s+1);
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
    if(pi[len]>0)
    {
        for(i=2;i<len;i++)
        {
            if(pi[i]==pi[len])
            {
                for(j=1;j<=pi[len];j++)
                {
                    printf("%c",s[j]);
                }
                return 0;
            }
        }
        if(pi[pi[len]]>0)
        {
            for(i=2;i<len;i++)
            {
                if(pi[i]==pi[pi[len]])
                {
                    for(j=1;j<=pi[pi[len]];j++)
                    {
                        printf("%c",s[j]);
                    }
                    return 0;
                }
            }
            printf("Just a legend");return 0;
        }
        else
        {
            printf("Just a legend");return 0;
        }

    }
    else
    {
        printf("Just a legend");
    }
}
