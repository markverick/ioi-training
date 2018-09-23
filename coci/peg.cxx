#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[15][15];
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
int main()
{
	int i,j,k;
	for(i=2;i<=3;i++)
        scanf("%s",s[i]+4);
	for(i=4;i<=6;i++)
        scanf("%s",s[i]+2);
	for(i=7;i<=8;i++)
        scanf("%s",s[i]+4);
    int sum=0;
    for(i=2;i<=8;i++)
    {
        for(j=2;j<=8;j++)
        {
            for(k=0;k<4;k++)
            {
                if(s[i][j]=='o'&&s[i+dx[k]][j+dy[k]]=='.'&&s[i-dx[k]][j-dy[k]]=='o')
                    sum++;
            }
        }
    }
    printf("%d",sum);
}
