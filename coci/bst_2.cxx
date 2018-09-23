#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
set<long long> st;
set<long long>::iterator it;
long long h[300135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	long long i,j,k,n,cot=0,mc,a;
	scanf("%lld",&n);
	scanf("%lld",&a);
//	cot++;
	h[a]=0;
	st.insert(a);
	printf("%lld\n",cot);
	for(i=2;i<=n;i++)
    {
        mc=0;
        scanf("%lld",&a);
        it=st.lower_bound(a);
        if(it==st.begin())
            h[a]=h[*it]+1,cot+=h[a];
        else if(it==st.end())
        {
            it--;
            h[a]=h[*it]+1;cot+=h[a];
        }
        else
        {
            mc=max(mc,h[*it]);
            it--;
            mc=max(mc,h[*it]);
            h[a]=mc+1;cot+=h[a];
        }
        printf("%lld\n",cot);
        st.insert(a);
    }
}
