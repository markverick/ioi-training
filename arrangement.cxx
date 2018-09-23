#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define X first
#define Y second
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using olo=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
int a[300135];
olo<int> swag;
int main()
{
    int n,i,mc=0,cot=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;i++)
    {
        mc=max(mc,a[i]);
        if(a[i]<mc)
        {
            cot+=1+swag.order_of_key(a[i]);
        }
        swag.insert(a[i]);
    }
    printf("%d",cot);
}
