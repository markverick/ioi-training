#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char maps[55][55];
char m[305][305];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,l,r,c,x,y;
	scanf("%d %d %d %d",&r,&c,&x,&y);
	for(i=0;i<r;i++)
    {
        scanf("%s",maps[i]);
        for(j=0;j<c;j++)
        {
            for(k=0;k<x;k++)
            {
                for(l=0;l<y;l++)
                    m[i*x+k][j*y+l]=maps[i][j];
            }
        }
    }
    for(i=0;i<r*x;i++)
    {
        for(j=0;j<c*y;j++)
            printf("%c",m[i][j]);
        printf("\n");
    }
}
