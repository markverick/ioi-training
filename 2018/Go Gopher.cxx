#include<bits/stdc++.h>
using namespace std;
int maps[5][500];
int main()
{
	int T,t,i,j,k,a,sq,ct,x,y,fin;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		memset(maps,0,sizeof maps);
		scanf("%d",&a);
		fin=0;
		sq=(a-1)/9+1;
		for(i=1;i<=sq;i++)
		{
			ct=0;
			while(ct<9)
			{
				printf("2 %d\n",i*3);
				fflush(stdout);
				scanf("%d %d",&x,&y);
				if(x==0&&y==0)
				{
					fin=1;
					break;
				}
				if(maps[x][y]==0)
					maps[x][y]=1,ct++;
			}
			if(fin==1)
				break;	
		}
	}
}