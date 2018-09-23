#include<bits/stdc++.h>
using namespace std;
char s[100135];
list<char> ls;
list<char> ::iterator it;
int main()
{
    int i,j,k,len;
    while(scanf("%s",&s)!=EOF)
    {
        len=strlen(s);
        ls.clear();
        it=ls.begin();
        for(i=0;i<len;i++)
        {
            if(s[i]=='[')
            {
                it=ls.begin();
            }
            else if(s[i]==']')
            {
                it=ls.end();
            }
            else
            {
                ls.insert(it,s[i]);
            }
        }
        for(it=ls.begin();it!=ls.end();it++)
        {
            printf("%c",*it);
        }
        printf("\n");
    }
}
