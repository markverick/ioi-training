#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define X first
#define Y second
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using o_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
vector<pair<int,int> > p;
vector<pair<int,int> >::iterator it;
int a[100135];
o_set<int> s;
int main()
{
    int T,n,i,j,k;

    scanf("%d",&T);
    while(T--)
    {
        s.clear();
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        stack<int> st;
        for(i=n;i>=1;i--)
        {
            s.insert(a[i]);
            st.emplace(s.order_of_key(a[i]));
        }
        for(i=1;i<=n;i++)
        {
            printf("%d ",st.top());
            st.pop();
        }
    }

}
