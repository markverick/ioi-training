#include<bits/stdc++.h>
using namespace std;
char s[2000];
int indent=0;
void doind()
{
    int x=indent*2;
    while(x>0)
        printf(" "),x--;
}
int main()
{
    int n,i,j,k,len;
    scanf("%s",s+1);
    len=strlen(s+1);
    for(i=1;i<=len;i++)
    {
        if(s[i]=='{')
        {
            doind();
            printf("{\n");
            if(s[i+1]=='}')
            {
                indent++;
            }
            else
            {
                indent++;
            }
        }
        else if(s[i]=='}')
        {
            indent--;
                doind();
            if(s[i+1]==',')
            {
                printf("}");
            }
            else
            {
                printf("}\n");
            }
        }
        else if(s[i]==',')
        {
            if(s[i-1]=='{'||s[i-1]==',')
                doind();
            printf(",\n");
        }
        else
        {
            if(s[i-1]=='{'||s[i-1]=='}'||s[i-1]==',')
                doind();
            printf("%c",s[i]);
            if(s[i+1]=='}'||s[i+1]=='{')
                printf("\n");
        }
    }
}
