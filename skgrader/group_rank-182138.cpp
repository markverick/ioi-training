#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using o_set=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
o_set<int> st[100135];
int p[100135];
stack<int> tmp;
int Find(int a)
{
    while(p[a]!=a)
    {
        a=p[a];
    }
    return a;
}
int main()
{
    int T,i,j,k,n,o,ch,x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&o);
        for(i=1;i<=n;i++)
        {
            p[i]=i;
            st[i].insert(i);
        }
        for(i=1;i<=o;i++)
        {
            scanf("%d",&ch);
            if(ch==1)
            {
                scanf("%d %d",&x,&y);
                y=Find(y);
                for(auto it=st[y].begin();it!=st[y].end();it++)
                {
                    st[x].insert(*it);
                }
                //st[y].clear();
                p[y]=x;

            }
            else
            {
                scanf("%d",&x);
                y=x;
                x=Find(x);
                printf("%d\n",st[x].size()-st[x].order_of_key(y));
            }
        }
        for(i=1;i<=n;i++)
        {
            st[i].clear();
        }
    }
}
