#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[111];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,len;
	scanf("%s",s);
	len=strlen(s);
	printf("%c",s[0]);
	for(i=1;i<len;i++)
    {
        if(s[i]=='-')
            printf("%c",s[i+1]);
    }
}
