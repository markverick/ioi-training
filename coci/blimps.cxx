#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[20];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k=0,len;
	for(i=1;i<=5;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        for(j=0;j<len-2;j++)
        {
            if(s[j]=='F'&&s[j+1]=='B'&&s[j+2]=='I')
            {
                printf("%d ",i);k=1;
                break;
            }
        }
    }
    if(!k)
        printf("HE GOT AWAY!");
}
