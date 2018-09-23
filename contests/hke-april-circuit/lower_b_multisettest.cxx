#include<bits/stdc++.h>
#define DT distance
using namespace std;

int main()
{
    multiset<int> st;
    st.insert(1);
    st.insert(1);
    st.insert(1);
    st.insert(2);
    st.insert(2);
    st.insert(2);
    st.insert(3);
    st.insert(3);
    st.insert(3);
    printf("%d\n",DT(st.begin(),st.lower_bound(2)));
    printf("%d\n",DT(st.begin(),st.upper_bound(2)));
}
