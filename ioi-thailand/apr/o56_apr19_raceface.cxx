#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MI 1000000000
#define EPS 0.0000000001
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
using namespace __gnu_pbds;
int v[100135],x[100135],sm[1000135];
double y[100135];
pair<int,double> p[100135];
template<typename T>
using oset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
oset<double> st;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,mc=0;
	double yy;
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		scanf("%d %d",&v[i],&x[i]);
		y[i]=(double)x[i]/v[i];
		p[i]=MP(x[i],y[i]);
	}
	sort(&p[1],&p[n]);
	scanf("%d",&v[n]);
	j=1;
	for(i=0;i<=p[n-1].X;i++)
	{
		yy=(double)i/v[n];
		while(j<n&&p[j].X<i)
		{
			st.insert(p[j].Y);
			j++;
		}
		sm[i]=(int)st.size()-st.order_of_key(yy-EPS);
		while(j<n&&p[j].X<=i)
			st.insert(p[j].Y),j++,sm[i]++;
	}
	j=n-1;st.clear();
	for(i=p[n-1].X;i>=0;i--)
	{
		yy=(double)i/v[n];
		while(j&&p[j].X>i)
			st.insert(p[j].Y),j--;
		sm[i]+=(int)st.order_of_key(yy+EPS);
		mc=max(mc,sm[i]);
	}
	printf("%d\n",mc);
}