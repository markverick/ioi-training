#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int yo[1000005];
int main()
{
    int len,i,k,j;
    scanf("%s",s+1);
    len=strlen(s+1);
    k=0;
    yo[1]=0;
    for(i=2;i<=len;i++)
    {
        while(k>0&&s[k+1]!=s[i])
            k=yo[k];
        if(s[k+1]==s[i])
            k++;
        yo[i]=k;
    }
    for(i=1;i<=len;i++)
        printf("%d ",yo[i]);
    if(yo[len]==0)
    {
        printf("Just a legend\n");
        return 0;
    }
    for(i=2;i<len;i++)
    {
        if(yo[i]==yo[len])
        {
            for(j=1;j<=yo[len];j++)
                printf("%c",s[j]);
            return 0;
        }
    }
    if(yo[yo[len]]==0)
        printf("Just a legend\n");
    else
        for(j=1;j<=yo[yo[len]];j++)
                printf("%c",s[j]);

}
