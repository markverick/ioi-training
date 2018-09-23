#include<bits/stdc++.h>
using namespace std;
char str[135];
int main()
{
    scanf("%s",str+1);
    int len=strlen(str+1),i,j;
    for(i=1;i<=len;i++)
    {
        if(str[i]=='N')
            str[i]=0;
        else if(str[i]=='E')
            str[i]=1;
        else if(str[i]=='S')
            str[i]=2;
        else if(str[i]=='W')
            str[i]=3;
        else if(str[i]=='Z')
            str[i]=4;
    }
    str[0]=0;
    for(i=1;i<=len;i++)
    {
        if(str[i]==4)
        {
            printf("Z");
            continue;
        }
        for(j=0;j<(4+str[i]-str[i-1])%4;j++)
            printf("R");
        printf("F");
    }
}
