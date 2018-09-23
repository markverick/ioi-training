#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[222];
int hsh[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,len;
	scanf("%s",s);
	len=strlen(s);
	j=0;
	for(i=0;i<len;i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			while(j%4)j++;
		}
		j++;
	}
	printf("%d\n",j-len);
}