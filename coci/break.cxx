#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int len;
string str;
vector<int> s;
vector<int> Pow(int p)
{
	if(p==0)
		return s;
	// printf("%d\n",p);
	vector<int> b=Pow(p/2),pos=b,d=b,ret=b;
	int i;
	for(i=0;i<b.size();i++)
	{
		pos[b[i]]=i;
	}
	for(i=0;i<b.size();i++)
		d[pos[pos[i]]]=i;
	if(p%2)
	{
		for(i=0;i<(b.size()+1)/2;i++)
		{
			ret[i]=d[i*2];
		}
		for(i=(b.size()+1)/2;i<b.size();i++)
		{
			ret[b.size()-i+(b.size()+1)/2-1]=d[(i-(b.size()+1)/2)*2+1];
		}
	}
	else
	{
		for(i=0;i<b.size();i++)
			ret[i]=d[i];
	}
	// printf("Case %d:\n",p);
	// for(i=0;i<b.size();i++)
	// 	printf("%d ",ret[i]);
	// printf("\n");
	return ret;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
	cin >> n >> str;
	for(i=0;i<str.size();i++)
		s.push_back(i);
	vector<int> out=Pow(n);
	for(i=0;i<out.size();i++)
		cout << str[out[i]];
}