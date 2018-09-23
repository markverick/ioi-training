#include<bits/stdc++.h>
#define MP make_pair
using namespace std;
string s,t,L,R;
map<string,int> hsh;
typedef class node
{
public:
	int hi=0;
	pair<char,char> p;
	map<pair<int,int>,node*> adj;
	node(pair<int,int> t)
	{
		p=t;hi=0;
	}
}node;
typedef node* pnode;
int main()
{
	int n,i,j,k,mc=0,sm,m;
	pair<int,int> p;
	cin >> n;
	pnode root=new node(MP('$','$')),t,it;
	for(i=1;i<=n;i++)
	{
		cin >> s;
		t=root;
		sm=1;m=0;
		for(j=0;j<s.size();j++)
		{
			p=MP(s[j],s[s.size()-1-j]);
			if(t->adj.find(p)==t->adj.end())
			{
				it=new node(p);
				t->adj[p]=it;
			}
			else
			{
				it=t->adj[p];
				m=max(m,it->hi);
			}
			t=it;
		}
		t->hi=m+1;
		mc=max(mc,m+1);
	}
	printf("%d",mc);
}