#include<bits/stdc++.h>
using namespace std;
multiset<long long> st;
int main()
{
    long long n,l,h,i,j,k,a,x,y,m;
    double z;
    scanf("%lld %lld %lld",&n,&l,&h);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&m);
        for(j=1;j<=m;j++)
        {
            scanf("%lld",&a);
            st.insert(a);
        }
        scanf("%lld %lld",&x,&y);
        z=(double)l+(double)h*x/y;
        z=ceil(z);
        auto it=st.lower_bound(z);
        st.erase(it,st.end());
        printf("%d\n",st.size());
    }
}
