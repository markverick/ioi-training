#include<bits/stdc++.h>
using namespace std;
int len;
char s[1000];
int main()
{
    scanf("%s",s);
    int sum=0,i;
    len=strlen(s);
    for(i=0;i<len;i++)
    {
        sum+=s[i]-'0';
    }
    printf("%d\n",sum);
}
