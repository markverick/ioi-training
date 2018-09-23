#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int n,m;
char str[135],cfg[135];
map<string,int> hsh;
inline char inv(char x)
{
	if(x=='B')return 'W';
	else return 'B';
}
void rotate(string &st)
{
	if(st.empty())return;
	char tmp=st[0];
	for(int i=0;i<st.size()-1;i++)
	{
		st[i]=st[i+1];
	}
	st[st.size()-1]=tmp;
}
string s,mn;
int cot=0;
void gen(int idx,string st)
{
	// printf("%d %d %s\n",idx,m,st.c_str());
	if(idx==m)
	{
		if(hsh[st]==0)
		{
			printf("%s\n",st.c_str());
			cot++;
		}
		for(int i=0;i<n;i++)
		{
			hsh[st]=1;
			rotate(st);
		}
		return;
	}
	string cf=st;
	cf[0]='B';
	for(int i=1;i<n;i++)
	{
		if(st[i]=='B')
		{
			cf[i]=cf[i-1];
		}
		else
		{
			cf[i]=inv(cf[i-1]);
		}
	}
	gen(idx+1,cf);
	for(int i=0;i<n;i++)
		cf[i]=inv(cf[i]);
	gen(idx+1,cf);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d %d",&n,&m);
	scanf("%s",str);
	for(k=1;k<=m;k++)
	{
		for(i=0;i<n;i++)
		{
			if(str[i]==str[(i+1)%n])
				cfg[i]='B';
			else
				cfg[i]='W';
		}
		strcpy(str,cfg);
	}

	printf("%s\n",str);
	gen(0,str);
	printf("%d\n",cot);
}