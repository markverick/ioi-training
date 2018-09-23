#include<bits/stdc++.h>
#define X first
#define Y second
#define MP 1
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[111][111];
int main()
{
	int r,c,i,j,k,x,y;
	scanf("%d %d",&r,&c);
    for(i=1;i<=r;i++)
    {
        scanf("%s",s[i]+1);
        for(j=1;j<=c;j++)
        {
            s[i][2*c-j+1]=s[i][j];
        }
        for(j=1;j<=c*2;j++)
        {
            s[r*2-i+1][j]=s[i][j];
        }
    }
    scanf("%d %d",&x,&y);
    if(s[x][y]=='.')
        s[x][y]='#';
    else
        s[x][y]='.';
    for(i=1;i<=r*2;i++)
        printf("%s",s[i]+1),printf("\n");
}
