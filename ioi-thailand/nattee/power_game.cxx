#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[100135],b[100135];
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(&a[1],&a[n+1]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    sort(&b[1],&b[n+1]);
    j=n;
    for(i=n;i>=1;i--)
    {
        if(a[j]>b[i])
        {
            sum+=a[j];
            j--;
        }
    }
    printf("%d",sum);
}
