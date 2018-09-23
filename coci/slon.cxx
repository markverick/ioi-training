#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[100135];
stack<char> op;
vector<char> out;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,p,m;
	scanf("%s",s);
	n=strlen(s);
	scanf("%d %d",&p,&m);
	for(i=0;i<n;i++)
	{
		if(s[i]=='x')
		{
			out.emplace_back(s[i]);
		}
		else if(s[i]>='0'&&s[i]<='9')
		{
			for(j=i;j<n;j++)
			{
				if(s[j]<'0'||s[j]>'9')
					break;
			}
			for(k=j-1;k>=i;k--)
				out.emplace_back(s[k]);
		}
		
	}
}