#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1000135];
deque<pair<int,int> > dq;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,m,mn=MI;
	scanf("%d %d",&n,&m);
	m=n-m;
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(&a[1],&a[n+1]);
    for(i=2;i<=m;i++)
    {
        while(!dq.empty()&&dq.back().X>a[i]-a[i-1])
            dq.pop_back();
        dq.emplace_back(a[i]-a[i-1],i);
    }
    mn=a[m]-a[1]+dq.front().X;
    for(i=m+1;i<=n;i++)
    {
        while(!dq.empty()&&dq.front().Y<=i-m)
            dq.pop_front();
        while(!dq.empty()&&dq.back().X>a[i]-a[i-1])
            dq.pop_back();
        dq.emplace_back(a[i]-a[i-1],i);
        mn=min(mn,a[i]-a[i-m+1]+dq.front().X);
    }
    printf("%d",mn);
}
