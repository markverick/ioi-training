#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[1000];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
    int i,j,k,n;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[1],&a[n+1]);
    n=unique(&a[1],&a[n+1])-&a[1];
    for(i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
}
