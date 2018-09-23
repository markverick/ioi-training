#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int dx[6]={1,1,0,2,1};
int dy[6]={1,0,1,1,2};
int hsh[6][1100][1100],maps[1135][1135],out[10135],cot[10135];
int main()
{
	// freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,l,x,y,r,c,m,fk=0,st=0;
	while(scanf("%d %d %d %d",&n,&r,&c,&m)!=EOF)
	{
		if(st) printf("\n");
		st=1;
		memset(hsh,0,sizeof hsh);
		memset(maps,0,sizeof maps);
		memset(out,0,sizeof out);
		memset(cot,0,sizeof cot);
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				scanf("%d",&maps[i][j]);
				cot[maps[i][j]]++;
			}
		}
		fk=0;
		for(i=2;i<=n;i++)
		{
			if(cot[i]!=cot[i-1]&&cot[i]+1!=cot[i-1])
				fk=1;
		}
		if(cot[1]!=cot[n]&&cot[1]!=cot[n]+1)fk=1;
		if(fk)
		{
			printf("ERROR\n");
			continue;
		}
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(maps[i][j]==0)continue;
				for(k=0;k<5;k++)
				{
					x=i;y=j;
					l=1;
					while(l<=m)
					{
						if(hsh[k][x][y])break;
						hsh[k][x][y]=1;
						if(maps[(x+dx[k])%r][(y+dy[k])%c]==maps[x][y])
							x+=dx[k],y+=dy[k],l++;
						else
							break;
					}
					out[maps[i][j]]=max(out[maps[i][j]],l);
				}
			}
		}
		fk=0;j=0;
		for(i=1;i<=n;i++)
		{
			// printf("%d\n",out[i]);
			if(out[i]>=m)
			{
				fk=1;
				printf("PLAYER %d\n",i);
				j++;
				break;
			}
		}
		if(!fk)
			printf("NO WINNERS\n");
	}
}