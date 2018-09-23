#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[200135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n*2;i++)
        scanf("%d",&a[i]);
    sort(&a[1],&a[n*2+1]);
    printf("%d",a[n]);
}
