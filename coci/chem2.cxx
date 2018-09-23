#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[111];
int vow[500];
int main()
{
	int i,j,k,n;
	vow['a']=1;
	vow['e']=1;
	vow['i']=1;
	vow['o']=1;
	vow['u']=1;
	while(scanf("%s",s+1)!=EOF)
    {
        n=strlen(s+1);
        for(i=2;i<n;i++)
        {
            if(s[i-1]==s[i+1]&&vow[s[i-1]]==1)
            {
                s[i]=0;s[i+1]=0;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(s[i])
                printf("%c",s[i]);
        }
        printf(" ");
    }
}
