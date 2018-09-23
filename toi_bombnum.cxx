#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define X first
#define Y second
#define MP make_pair
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using o_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
o_set<pair<int,int> > or_val;
o_set<pair<int,int> > val_or;
o_set<pair<int,int> >::iterator it;
int n;
int a[100135];
int main()
{
    int i,j,k,tmp,tmp2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
        or_val.insert({i,a[i]});
        val_or.insert({a[i],i});
    }
    int sz;
    while(or_val.size()>1)
    {
        sz=or_val.size();
        it=val_or.find_by_order(sz/2);
        tmp=(*it).Y;
        //printf("%d\n",(*it).X);
        it=or_val.lower_bound(MP(tmp ,0) );
        it++;
        if(it==or_val.end())
            it=or_val.begin();
        tmp2=(*it).X;
        val_or.erase(val_or.lower_bound( MP( (*or_val.lower_bound(MP(tmp ,0) ) ).Y ,0 ) ) );
        val_or.erase(val_or.lower_bound( MP( (*or_val.lower_bound(MP(tmp2,0) ) ).Y ,0 ) ) );
        or_val.erase(or_val.lower_bound(MP(tmp,0) ) );
        or_val.erase(or_val.lower_bound({tmp2,0}) );

    }
    printf("%d",(*val_or.begin() ).X+1);
}
