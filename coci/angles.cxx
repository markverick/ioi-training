#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[14],b[14];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k,g=360;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        g=__gcd(g,a[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
        if(b[i]%g==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
