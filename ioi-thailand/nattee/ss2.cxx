#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int qs[1135],ms[1135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
        scanf("%d",&qs[i]),qs[i]+=qs[i-1],ms[i]=MI;
    for(i=1;i<=n;i++)
        for(j=1;j<=n-i+1;j++)
            ms[i]=min(ms[i],qs[j+i-1]-qs[j-1]);
    while(m--)
    {
        scanf("%d",&k);
        printf("%d\n",upper_bound(&ms[1],&ms[n+1],k)-&ms[1]);
    }
}
