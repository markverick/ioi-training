#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[5];
int main()
{
	int i,j,k;
	for(i=1;i<=3;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[1],&a[4]);
    if(a[2]-a[1]==a[3]-a[2])
    {
        printf("%d",a[3]+a[3]-a[2]);
    }
    else if(a[2]-a[1]<a[3]-a[2])
    {
        printf("%d",(a[3]+a[2])/2);
    }
    else
        printf("%d",(a[1]+a[2])/2);
}
