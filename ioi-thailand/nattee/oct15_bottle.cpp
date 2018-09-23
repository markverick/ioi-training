#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int h[100135];
set<pair<int,int> > st;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,a,x,cot;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
        st.insert(MP(-h[i],i));
    }
    vector<int> v;
    while(m--)
    {
        scanf("%d",&a);cot=0;
        while(!st.empty()&&-((*st.begin()).X)>a)
        {
            x=(*st.begin()).Y;
            st.erase(st.begin());cot++;
            v.emplace_back(x);
        }
        for(i=0;i<v.size();i++)
        {
            x=v[i];
            if(st.find(MP(-h[x+1],x+1))!=st.end())
                st.erase(st.find(MP(-h[x+1],x+1))),cot++;
            if(st.find(MP(-h[x-1],x-1))!=st.end())
                st.erase(st.find(MP(-h[x-1],x-1))),cot++;
        }
        v.clear();
        printf("%d\n",cot);
    }
}
