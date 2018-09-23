#include<bits/stdc++.h>
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
	int i,j,k,len,cot=0;
	scanf("%s",s);
	len=strlen(s);
	for(i=0;i<len;i++)
    {
        if(s[i]=='c'&&s[i+1]=='=')
            i++;
        if(s[i]=='c'&&s[i+1]=='-')
            i++;
        if(s[i]=='d'&&s[i+1]=='z'&&s[i+2]=='=')
            i+=2;
        if(s[i]=='d'&&s[i+1]=='-')
            i++;
        if(s[i]=='l'&&s[i+1]=='j')
            i++;
        if(s[i]=='n'&&s[i+1]=='j')
            i++;
        if(s[i]=='s'&&s[i+1]=='=')
            i++;
        if(s[i]=='z'&&s[i+1]=='=')
            i++;
        cot++;
    }
    printf("%d",cot);
}
