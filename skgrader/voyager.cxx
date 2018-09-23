#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int dx[6]={-1,0,1,0};
int dy[6]={0,1,0,-1};
///-------{ ^,>,v,<};
///-------{0, 1,2,3};
int sl[6]={1,0,3,2};
int bk[6]={3,2,1,0};
char ch[6]={'U','R','D','L'};
int r,c,ste[531][531][6],fk;
char maps[531][531];
int dfs(int x,int y,int d)
{
    if(x<1||x>r||y<1||y>c||maps[x][y]=='C')
        return 0;
    if(ste[x][y][d])
    {
        fk=1;
        return 0;
    }
    ste[x][y][d]=1;
    switch(maps[x+dx[d]][y+dy[d]])
    {
    case '.':
        return dfs(x+dx[d],y+dy[d],d)+1;
    case '/':
        return dfs(x+dx[d],y+dy[d],sl[d])+1;
    case '\\':
        return dfs(x+dx[d],y+dy[d],bk[d])+1;
    default:
        return 1;
    }
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,sx,sy,mc=0;
	scanf("%d %d",&r,&c);
	for(i=1;i<=r;i++)
	{
        scanf("%s",maps[i]+1);
	}
	scanf("%d %d",&sx,&sy);
	for(i=0;i<4;i++)
    {
        memset(ste,0,sizeof ste);
        fk=0;
        k=dfs(sx,sy,i);
        if(fk==1)k=MI;
        if(mc<k)
            mc=k,j=i;
    }
    if(mc<MI)
        printf("%c\n%d",ch[j],mc);
    else
        printf("%c\nVoyager",ch[j]);
    return 0;
}
