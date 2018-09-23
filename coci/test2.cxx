#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[1000135];
int hsh[1135][1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,r=28,c=26,len;
	scanf("%s",s);
	len=strlen(s);
	int x=1,y=1;
	hsh[1][1]=1;
    for(i=0;i<len;i++)
    {
        if(s[i]=='U')
            x--;
        else if(s[i]=='D')
            x++;
        else if(s[i]=='R')
            y++;
        else
            y--;
        hsh[x][y]=1;
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(hsh[i][j]==0)
                printf("[%d][%d]\n",i,j);
        }
    }
}
