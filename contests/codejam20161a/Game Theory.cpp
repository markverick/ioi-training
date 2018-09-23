#include<bits/stdc++.h>
using namespace std;
char name[10],str[135];
int hsh[30];
int main()
{
    int T,i,j=0,len;
    scanf("%d",&T);
    while(T--)
    {
        j=0;
        memset(hsh,0,sizeof hsh);
        scanf("%s %s",name,str);
        len=strlen(str);
        for(i=0;i<len;i++)
        {
            hsh[str[i]-'a']++;
        }
        for(i=0;i<26;i++)
        {
            j^=hsh[i];
        }
        if(name[0]=='T')
        {
            if(j==0)
                printf("Varun\n");
            else
                printf("Tarun\n");
        }
        else
        {
            if(j==0)
                printf("Tarun\n");
            else
                printf("Varun\n");
        }
    }
}
