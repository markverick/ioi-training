#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using o_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
o_set<int> st;
int x[300135];
int main()
{
    int a,b,c,n,k,i,j;
    while(scanf("%d %d %d %d %d",&a,&b,&c,&n,&k)!=EOF)
    {
        x[0]=a;
        for(i=1;i<n;i++)
        {
            x[i]=(x[i-1]*b+c)%65536;
        }
        for(i=0;i<k-1;i++)
        {
            st.insert(x[i]);
        }
        long long sum=0;
        for(i=k-1;i<n;i++)
        {
            st.insert(x[i]);

            //if(k%2==1)
           // {
                sum+=*st.find_by_order(i-k/2);
            //}
            /*
            else
            {
                sum+=(*st.find_by_order(i-k/2)+*st.find_by_order(i-k/2+1))/2;
            }*/
            st.erase(x[1+i-k]);
        }
        printf("%lld\n",sum);
        st.clear();
    }
}
