#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
multiset<int> st,ts;
multiset<int> ::iterator it;
int sk[100135],ks[100135];
int a[100135],b[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,mc;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i],&ks[i]);
    }
    sort(&a[1],&a[n+1]);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&b[i],&sk[i]);
        st.insert(sk[i]-b[i]);
    }
    j=1;
    for(i=1;i<=n;i++)
    {
        while(j<=n&&b[j]<a[i])
        {
            st.erase(st.find(sk[j]-b[j]));
            ts.insert(b[j]+sk[j]);
            j++;
        }
        it=st.end();mc=-MI;
        if(it!=st.begin())
        {
            it--;
            mc=max(mc,*it+ks[i]+a[i]);
        }
        it=ts.end();
        if(it!=ts.begin())
        {
            it--;
            mc=max(mc,*it+ks[i]-a[i]);
        }
        printf("%d\n",mc);
    }

}
