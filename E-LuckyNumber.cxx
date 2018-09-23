#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int ha[1135],hb[1135];
char s[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,len,mca=0,mcb=0;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		len=strlen(s);
		for(i=0;i<len-1;i++)
		{
			ha[(s[i]-'0')*10+s[i+1]-'0']++;
		}
		for(i=0;i<len-2;i++)
		{
			hb[(s[i]-'0')*100+(s[i+1]-'0')*10+s[i+2]-'0']++;
		}
		for(i=0;i<=1000;i++)
		{
			mca=max(mca,ha[i]);
			mcb=max(mcb,hb[i]);
		}
	}


	for(i=0;i<=1000;i++)
	{
		if(ha[i]==mca)printf("%02d ",i);
	}
	printf("\n");
	for(i=0;i<=1000;i++)
	{
		if(hb[i]==mcb)printf("%03d ",i);
	}
}