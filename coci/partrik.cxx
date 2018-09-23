#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[500135],n;
stack<pair<int,int> > st;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	long long sm=0;
	pair<int,int> tmp;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		tmp=MP(-1,-1);
		while(!st.empty()&&st.top().X<a[i])st.pop();
		if(!st.empty()&&st.top().X==a[i])
		{
			tmp=st.top();
			st.pop();
		}
		if(!st.empty())
			sm++;
		if(tmp.X>=0)
			sm+=tmp.Y;
		tmp.Y++;
		if(tmp.X>=0)
			st.emplace(tmp);
		else st.emplace(a[i],1);
	}
	while(!st.empty())
		st.pop();
	for(i=n;i>=1;i--)
	{
		while(!st.empty()&&st.top().X<=a[i])st.pop();
		if(!st.empty())sm++;
		st.emplace(a[i],1);
	}
	printf("%lld",sm);
}