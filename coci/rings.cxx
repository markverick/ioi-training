#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n,x,r,g;
	scanf("%d",&n);
	scanf("%d",&x);
	for(i=2;i<=n;i++)
    {
        scanf("%d",&r);
        g=__gcd(x,r);
        printf("%d/%d\n",x/g,r/g);
    }
}
