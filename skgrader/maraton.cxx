#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[35][35];
int dx[10]={1,1,1,0,0,-1,-1,-1};
int dy[10]={-1,0,1,-1,1,-1,0,1};
int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(k=0;k<8;k++)
            {
                if(s[i][j]!='.'&&s[i][j]==s[i+dx[k]][j+dy[k]]&&s[i][j]==s[i-dx[k]][j-dy[k]])
                {
                    printf("%c",s[i][j]);
                    return 0;
                }
            }
        }
    }
    printf("ongoing");
}
