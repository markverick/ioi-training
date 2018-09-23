#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s1[135],ch[5],s2[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int a,b,i,j,k;
	scanf("%s %s %s",s1,ch,s2);
	a=strlen(s1);
	b=strlen(s2);
	if(ch[0]=='+')
    {
        if(a==b)
        {
            printf("2");
            for(i=1;i<a;i++)
                printf("0");
        }
        else
        {
            for(i=max(a,b);i>=1;i--)
            {
                if(i==a||i==b)
                    printf("1");
                else
                    printf("0");
            }
        }
    }
    else
    {
        printf("1");
        for(i=1;i<=a-1+b-1;i++)
            printf("0");
    }
}
