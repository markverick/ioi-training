#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
multiset<long long> st;
multiset<long long> Sum;
multiset<long long> ::iterator it,jt;
long long a[100135],qs[100135],p[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n;
	scanf("%I64d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    st.insert(0);
    st.insert(n+1);
    Sum.insert(qs[n]);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d",&p[i]);
        it=st.lower_bound(p[i]);
        jt=it;jt--;
        Sum.erase(Sum.find(qs[*it-1]-qs[*jt]));
        Sum.insert(qs[*it-1]-qs[p[i]]);
        Sum.insert(qs[p[i]-1]-qs[*jt]);
        st.insert(p[i]);
        it=Sum.end();it--;
        printf("%I64d\n",*it);
    }
}
