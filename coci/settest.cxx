#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	set<int> st;
	int a[]={1,2,3,-4};
    st.insert(10);
    st.insert(1);
    st.insert(-1);
    st.insert(50);
    for(auto &x:st)
    {
        printf("%d\n",x);
    }
    for(auto &y:a)
    {
        printf("%d\n",y);
    }
}
