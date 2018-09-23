#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[135],b[135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,sum=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    b[n]=a[n];
    for(i=n-1;i>=1;i--)
        b[i]=min(a[i],b[i+1]-1);
    for(i=1;i<=n;i++)
        sum+=max(0,a[i]-b[i]);
    printf("%d",sum);
}
