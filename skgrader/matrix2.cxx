#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[421][421],qa[421][421],qb[421][421];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,b,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&maps[i][j]);
        }
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            qa[i][j]=qa[i-1][j-1]+maps[i][j];
    for(i=1;i<=n;i++)
        for(j=n;j>=1;j--)
            qb[i][j]=qb[i-1][j+1]+maps[i][j];
    int mc=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            b=n-max(i,j);
            for(k=0;k<=b;k++)
            {
                mc=max(mc,qa[i+k][j+k]-qa[i-1][j-1]-qb[i+k][j]+qb[i-1][j+k+1]);
            }
        }
    }
    printf("%d",mc);
}
