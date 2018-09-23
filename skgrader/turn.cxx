#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int dx[6]={1,-1,0,0};
int dy[6]={0,0,1,-1};
char maps[11][11];
int deg[11][11];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,r,c;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
    {
        scanf("%s",maps[i]+1);
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            for(k=0;k<4;k++)
            {
                if(maps[i+dx[k]][j+dy[k]]=='.')
                    deg[i][j]++;
            }
        }
    }
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(maps[i][j]=='.'&&deg[i][j]<=1)
            {
                printf("1");
                return 0;
            }
        }
    }
    printf("0");
}
