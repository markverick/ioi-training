#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,hp,d,m,s;
double jum[23][531];
double dp(int idx,int val)
{
	if(jum[idx][val]>=-0.5)
		return jum[idx][val];
	if(idx==m+1)
	{
		return val+s>=hp;
	}
	if(val+s>=hp)
		return 1;
	double sm=0;int i;
	for(i=1;i<=d;i++)
	{
		sm+=dp(idx+1,val+i);
	}
	return jum[idx][val]=sm/d;
}
char str[135],ss[135],L[135],R[135];
int main()
{
	freopen("out3.txt","w",stdout);
	freopen("in3.txt","r",stdin);
	int T,t,i,j,k,len;
	double mc=0;
	scanf("%d",&T);
	for(t=1;t<=T;t++)
	{
		scanf("%d %d",&hp,&n);
		mc=0;
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=21;j++)
				for(k=0;k<=530;k++)
					jum[j][k]=-1.0;
			memset(L,0,sizeof L);
			memset(R,0,sizeof R);
			memset(ss,0,sizeof ss);
			memset(str,0,sizeof str);
			s=0;
			scanf("%s",str);
			sscanf(str,"%dd%s",&m,ss);
			len=strlen(ss);
			for(j=0;j<len;j++)
			{
				if(ss[j]=='+'||ss[j]=='-')
				{
					strcpy(R,ss+j);
					ss[j]=0;
					strcpy(L,ss);
					break;
				}
			}
			if(j==len)
				sscanf(ss,"%d",&d),s=0;
			else
			{
				sscanf(L,"%d",&d);
				sscanf(R,"%d",&s);
			}
			// printf("%d %d %d\n",m,d,s);
			mc=max(mc,dp(1,0));
		}
		printf("Case #%d: %f\n",t,mc);
	}	
}