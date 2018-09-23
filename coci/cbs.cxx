#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
char s[12][50135];
int a[12][50135];
int lft[50135];
vector<int> v[50135];
map<vector<int>,int> hsh;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int m,n,i,j,k;
	stack<int> st;
	scanf("%d %d",&m,&n);
	for(i=0;i<m;i++)
	{
		scanf("%s",s[i]+1);
		k=0;
		for(j=1;j<=n;j++)
		{
			if(s[i][j]=='(')k++;
			else k--;
			a[i][j]=k;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%2d ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		while(!st.empty())
			st.pop();
		for(j=1;j<=n;j++)
		{
			while(!st.empty()&&a[i][st.top()]>=a[i][j])
			{
				st.pop();
			}
			if(!st.empty())
				lft[j]=max(lft[j],st.top()+1);
			st.emplace(j);
		}
	}
	for(i=1;i<=n;i++)
	{
		printf("%2d ",lft[i]);
	}
	printf("\n");
	j=1;
	int sm=0;
	for(i=1;i<=n;i++)
	{
		for(k=0;k<m;k++)
			v[i].emplace_back(a[k][i]);
		while(j<lft[i])
			hsh[v[j]]--,j++;
		sm+=hsh[v[i]];
		hsh[v[i]]++;
		printf("%d <-> %d = %d\n",j,i,sm);
	}
	printf("%d",sm);
}