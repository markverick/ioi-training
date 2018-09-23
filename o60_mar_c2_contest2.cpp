#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using oset=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
int a[100135],b[100135],w[100135],p[100135];
inline int Find(int x)
{
    if(x==p[x])return x;
    return p[x]=Find(p[x]);
}
inline int Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    p[x]=y;
}
oset<int> st;
vector<int> v;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		p[i]=i;
		scanf("%d",&w[i]);
		st.insert(i);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		for(j=1;j<=n;j+=a*b)
		{
			for(k=j;k<j+a*b;j+=a)
			{
				
			}
		}
	}
}