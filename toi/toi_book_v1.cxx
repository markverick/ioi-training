#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using o_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
o_set<string> st;
string str;
char tmp[100];
int main()
{
    int i,j,k,n,a;
    scanf("%d",&n);
    for(j=1;j<=n;j++)
    {
        cin >> str;
        for(i=0;i<str.size();i++)
        {
            if(str[i]>='a')
                str[i]=str[i]+'A'-'a';
        }
        sprintf(tmp,"%06d",j);
        st.insert(str+tmp);
        printf("%d\n",st.order_of_key(str+tmp)+1);
    }
}


