#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
string s[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,fk;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> s[i];
	}
	for(i=1;i<=n;i++)
	{
		for(j=i;j<=n;j++)
		{
			if(s[i].size()!=s[j].size())continue;
			fk=0;
			for(k=0;k<s[i].size();k++)
			{
				if(s[i][k]!=s[j][s[j].size()-k-1])
				{
					fk=1;
					break;
				}
			}
			if(fk==0)
			{
				printf("%d %c\n",s[i].size(),s[i][s[i].size()/2]);
			}
		}
	}
	
}