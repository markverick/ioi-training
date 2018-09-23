#include<bits/stdc++.h>
using namespace std;
char s[55];
int main()
{
    int a=1,b=0,c=0,len,i;
    scanf("%s",s);
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        if(s[i]=='A')
            swap(a,b);
        else if(s[i]=='B')
            swap(b,c);
        else
            swap(a,c);
    }
    if(a==1)
        printf("1");
    else if(b==1)
        printf("2");
    else
        printf("3");
}
