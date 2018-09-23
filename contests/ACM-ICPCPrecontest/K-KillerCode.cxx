#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[100135];
int main()
{
    int len,i,j,k,cot=0;
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	while(gets(s))
    {
        len=strlen(s);
        for(i=0;i<len;i++)
        {
            if(s[i]==' ')
            {
                cot++;
            }
            else if(s[i]==',')
            {
                cot*=8;
            }
            else if(s[i]=='.')
            {
                printf("%c",'A'+cot);
                cot=0;
            }
        }
    }
}
