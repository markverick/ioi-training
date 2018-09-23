#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
string s;
int a[1135];
string lo,hi;
string operator -(string a,string b)
{
	string c=a;
	int i,j,len=c.size();
	for(i=len-1;i>=0;i--)
	{
		if(a[i]<'0')
			a[i]+=10,a[i-1]--;
		if(a[i]>=b[i])
			c[i]=a[i]-b[i];
		else
		{
			a[i-1]--;
			c[i]=10+a[i]-b[i];
		}
	}
	return c;
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,st;
	string L,H;
	cin >> s;
	n=s.size();
	for(i=0;i<n;i++)
		a[i]=s[i]-'0';
	st=0;
	hi=s;lo=s;
	for(i=1;i<n;i++)
	{
		if(a[i]%2==a[i-1]%2)
		{
			j=i;
			break;
		}
	}
	if(lo[j]=='0')
		lo.clear();
	else
		lo[j]--;
	if(hi[j]=='9')
		hi.clear();
	else
		hi[j]++;
	for(i=j+1;i<n;i++)
	{
		if((a[0]%2)^(i%2))
			lo[i]='9',hi[i]='1';
		else
			lo[i]='8',hi[i]='0';
	}
	if(!lo.empty())
		L=s-lo;
	if(!hi.empty())
		H=hi-s;
	if(!L.empty()&&!H.empty()&&L==H)
	{
		cout << lo << " " << hi;
	}
	else if(H.empty()||!L.empty()&&L<H)
		cout << lo;
	else
		cout << hi;
}