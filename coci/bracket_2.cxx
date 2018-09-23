#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int len,n,res[12],hsh[222];
char s[222];
vector<pair<int,int> > v;
set<string> Set;
void gen(int idx)
{
    if(idx==v.size())
    {
        int i;
        string ss;
        for(i=0;i<len;i++)
        {
            if(hsh[i]==0)
                ss.push_back(s[i]);
        }
        Set.insert(ss);
        return;
    }
    hsh[v[idx].X]=1;
    hsh[v[idx].Y]=1;
    gen(idx+1);
    hsh[v[idx].X]=0;
    hsh[v[idx].Y]=0;
    gen(idx+1);
}
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%s",s);
	len=strlen(s);
	stack<int> st;
	for(i=0;i<len;i++)
    {
        if(s[i]=='(')
            st.emplace(i);
        else if(s[i]==')')
            v.emplace_back(st.top(),i),st.pop();
    }
    gen(0);
    for(auto it=Set.begin();it!=Set.end();it++)
    {
        if(*it!=s)
            cout << *it << "\n";
    }
}
