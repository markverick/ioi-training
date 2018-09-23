#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]+=a[i-1];
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&k);
        upper_bound(&a[1],&a[n+1],k)-&a[1];
        printf("%d\n",upper_bound(&a[1],&a[n+1],k)-&a[1]);
    }
}
