#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    int i,j,k,n,len,sum=0;
    char x;
    scanf("%s",s);
    len=strlen(s);
    x='a';
    for(i=0;i<len;i++)
    {
        if(x<s[i])
            sum+=min(s[i]-x,26+x-s[i]);
        else
            sum+=min(x-s[i],26+s[i]-x);
        x=s[i];
    }
    printf("%d",sum);
}
