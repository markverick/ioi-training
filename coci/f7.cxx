#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[300135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,mc=0,cot=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[1],&a[n+1]);
    for(i=n;i>=1;i--)
    {
        mc=max(mc,a[i]+n-i+1);
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]+n>=mc)
            cot++;
    }
    printf("%d",cot);
}
