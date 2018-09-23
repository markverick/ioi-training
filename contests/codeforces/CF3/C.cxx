#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int maps[3][15],hsh[500],ste[3][15][3][15],out[3][15];
char s[30];
int dx[12]={0,0,1,1,1,-1,-1,-1};
int dy[12]={-1,1,-1,0,1,-1,0,1},n;
inline int chk(int x,int y)
{
	if(x>=0&&x<2&&y>=0&&y<13)
		return 1;
	return 0;
}
vector<tuple<char,int,int> > v;
void dfs(int idx,int x,int y)
{
	for(int i=0;i<8;i++)
	{
		if(!chk(x+dx[i],y+dy[i]))
			continue;
		if(ste[x][y][x+dx[i]][y+dy[i]]==0)
		{
			ste[x][y][x+dx[i]][y+dy[i]]=1;
			ste[x+dx[i]][y+dy[i]][x][y]=1;
			dfs(idx+1,x+dx[i],y+dy[i]);
			if(!v.empty())
			{
				v.emplace_back(s[idx],x,y);
			}
		}
	}
	if(v.empty()&&idx==n)
	v.emplace_back(s[idx],x,y);
}

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	char st;
	scanf("%s",s);
	n=strlen(s);
	for(i=0;i<n;i++)
	{
		hsh[s[i]]++;
		if(hsh[s[i]]==2)
		{
			st=s[i];
		}
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<13;j++)
		{
			memset(ste,0,sizeof ste);
			dfs(0,i,j);
			if(!v.empty())
				break;
		}
	}
	int a,b;
	char c;
	for(i=0;i<v.size();i++)
	{
		tie(a,b,c)=v[i];
		out[b][c]=a;
	}
	for(i=0;i<2;i++)
	{
		for(j=0;j<13;j++)
			printf("%c",out[i][j]);
		printf("\n");
	}
}