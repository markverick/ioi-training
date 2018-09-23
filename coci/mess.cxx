#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[111][111],qs[111][111];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,l,x,y,s,mn=1000000000;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        maps[x][y]++;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(maps[i][j]==0)
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+1;
            else
                qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1];

        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            s=n-max(i,j)+1;
            for(k=0;k<s;k++)
            {
                if(m%(k+1))continue;
                l=m/(k+1)-1;
                if(j+l>n)continue;
//                printf("%d %d\n",k+1,l+1);
                mn=min(mn,qs[i+k][j+l]-qs[i-1][j+l]-qs[i+k][j-1]+qs[i-1][j-1]);
            }
        }
    }
    printf("%d",mn);
}
