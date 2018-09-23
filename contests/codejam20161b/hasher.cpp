#include<bits/stdc++.h>
using namespace std;
char str[1000],hsh[30];
int main()
{
    int t,T,i,j,k,len;
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    scanf("%s",str);
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        hsh[str[i]-'a']=1;
    }
    for(i=0;i<26;i++)
    {
        if(hsh[i])
        {
            printf("%c ",'a'+i);
        }
    }
}

