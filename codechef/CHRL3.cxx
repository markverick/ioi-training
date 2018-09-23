#include<bits/stdc++.h>
using namespace std;
int a;
multiset<int> st;
multiset<int> ::iterator it;
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    scanf("%d",&a);
    st.insert(a);
    for(i=2;i<=n;i++)
    {
        scanf("%d",&a);
        it=st.lower_bound(a+1);
        if(it==st.begin())
        {
            st.insert(a);
        }
        else
        {
            it--;
            st.erase(it);
            st.insert(a);
        }
    }
    printf("%d",st.size());
}
