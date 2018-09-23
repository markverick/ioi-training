#include<bits/stdc++.h>
using namespace std;
multiset<int> st;
int main()
{
    int i;
    st.insert(2);
    st.insert(2);
    st.insert(2);
    st.insert(3);
    st.insert(3);
    auto it=st.lower_bound(3);
    while(it!=st.end())
    {
        printf("%d ",*it);it++;
    }
}
