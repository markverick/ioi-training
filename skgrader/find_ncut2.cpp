#include<bits/stdc++.h>
#define MP make_pair
#define PB push_back
using namespace std;
char s[1200000];
char t[1200000];
int main()
{
    int T,i,j,k;
    scanf("%s %s",s,t);
    int lenS=strlen(s);
    int lenT=strlen(t);
    for(i=0;i<lenS-lenT;i++)
    {
        int shift=0;
        for(j=0;j<lenT;j++)
        {
            while(s[i+j+shift]=='X')
                shift++;
            if(s[i+j+shift]!=t[j])
                break;
            if(j==lenT-1)
            {
                for(k=0;k<lenT+shift;k++)
                {
                    s[i+k]='X';
                }
                while(i-lenT>=0&&s[i-lenT]=='X')
                    i-=lenT;
                i-=lenT;
            }
        }
    }
    for(i=0;i<lenS;i++)
    {
        if(s[i]!='X')
            printf("%c",s[i]);
    }
}


