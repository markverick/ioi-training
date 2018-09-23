#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char str[55],s[55][55],a[]="RPS";
int score(char a,char b)
{
	if(a==b)
		return 1;
	if(a=='S')
		return b=='P'?2:0;
	else if(a=='P')
		return b=='R'?2:0;
	else
		return b=='S'?2:0;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,len,i,j,k,mc,sm,sum=0,all=0;
	scanf("%d",&len);
	scanf("%s",str);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%s",s[i]);
	for(i=0;i<len;i++)
	{
		mc=0;
		for(k=0;k<3;k++)
		{
			sm=0;
			for(j=1;j<=n;j++)
				sm+=score(a[k],s[j][i]);
			mc=max(mc,sm);
		}
		sum+=mc;
		for(j=1;j<=n;j++)
			all+=score(str[i],s[j][i]);
	}
	printf("%d\n%d",all,sum);
}