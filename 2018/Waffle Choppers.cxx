#include<bits/stdc++.h>
using namespace std;
int R[135],C[135];
char maps[135][135];
vector<int> vx,vy;
int main()
{
	int r,c,x,y,i,j,k,t,T,S,pcs,I,choc,fk,sm,l;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		vx.clear();
		vy.clear();
		vx.emplace_back(0);
		vy.emplace_back(0);
		memset(R,0,sizeof R);
		memset(C,0,sizeof C);
		S=0;
		scanf("%d %d %d %d",&r,&c,&x,&y);
		pcs=(x+1)*(y+1);
		for(i=1;i<=r;i++)
		{
			scanf("%s",maps[i]+1);
			for(j=1;j<=c;j++)
			{
				if(maps[i][j]=='@')
				{
					R[i]++,S++;
				}
			}
		}
		for(j=1;j<=c;j++)
		{
			for(i=1;i<=r;i++)
				if(maps[i][j]=='@')C[j]++;
		}
		// printf("%d %d\n",S,pcs);
		if(S%pcs!=0||S%(x+1)!=0||S%(y+1)!=0)
		{
			printf("Case #%d: IMPOSSIBLE\n",t);
			continue;
		}
		I=1;
		fk=0;
		for(k=0;k<=x;k++)
		{
			sm=0;
			for(i=I;i<=r;i++)
			{
				sm+=R[i];
				if(sm>S/(x+1))break;
				if(sm==S/(x+1))
				{
					I=i+1;
					vx.emplace_back(I);
					break;
				}
			}
			// printf("! [%d] %d %d\n",k,sm,S/(x+1));
			if(sm!=S/(x+1))
			{
				fk=1;break;
			}
		}
		if(fk==1)
		{
			printf("Case #%d: IMPOSSIBLE\n",t);
			continue;
		}
		// printf("FU\n");
		I=1;
		fk=0;
		for(k=0;k<=y;k++)
		{
			sm=0;
			for(i=I;i<=c;i++)
			{
				sm+=C[i];
				if(sm>S/(y+1))break;
				if(sm==S/(y+1))
				{
					I=i+1;
					vy.emplace_back(I);
					break;
				}
			}
			if(sm!=S/(y+1))
			{
				fk=1;break;
			}
		}
		if(k)
		if(fk==1)
		{
			printf("Case #%d: IMPOSSIBLE\n",t);
			continue;
		}
		for(i=0;i<=x;i++)
		{
			for(j=0;j<=y;j++)
			{
				sm=0;
				for(k=vx[i];k<vx[i+1];k++)
				{
					for(l=vy[j];l<vy[j+1];l++)
					{
						if(maps[k][l]=='@')sm++;
					}
				}
				if(sm!=S/pcs)
				{
					fk=1;
					break;
				}
			}
		}
		if(fk==1) printf("Case #%d: IMPOSSIBLE\n",t);
		else printf("Case #%d: POSSIBLE\n",t);

	}
}