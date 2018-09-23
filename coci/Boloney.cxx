#include<bits/stdc++.h>
#define MI 1000000000
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
double a[135],b[135],mn=MI;
int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int i,j,k,n;
	scanf("%lf %lf",&a[0],&b[0]);
	mn=a[0]/b[0]*1000;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
        scanf("%lf %lf",&a[i],&b[i]);
    for(i=1;i<=n;i++)
    {
        a[i]=a[i]/b[i]*1000;
        mn=min(mn,a[i]);
    }
    printf("%f",mn);
}
