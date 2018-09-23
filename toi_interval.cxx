#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define X first
#define Y second
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using o_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
pair<long long,long long> a[100135];
o_set<long long> y;
int main()
{
    long long n,i,j,k;
    scanf("%lld",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&a[i].X,&a[i].Y);
    }
    sort(&a[1],&a[n+1]);
    long long sum=0,sz;
    for(i=1;i<=n;i++)
    {
        sz=y.size();
        sum+=sz-y.order_of_key(a[i].X+1);
        y.insert(a[i].Y);
    }
    printf("%lld",sum);
}
