#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[1000135],t[1000135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,ls,lt,fk=0;
	vector<char> v;
	scanf("%s %s",s,t);
	ls=strlen(s);
	lt=strlen(t);
	for(i=0;i<ls;i++)
	{
		v.emplace_back(s[i]);
		fk=0;
		while(fk==0)
		{
			fk=0;
			if(v.size()>=lt)
			{
				for(j=1;j<=lt;j++)
				{
					if(v[v.size()-j]!=t[lt-j])
						fk=1;
				}
				if(fk==0)
				{
					v.resize(v.size()-lt);
				}
			}
			else
				break;
		}
	}
	for(i=0;i<v.size();i++)
		printf("%c",v[i]);
	if(v.empty())
		printf("FRULA");
}