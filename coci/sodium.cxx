#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;
int a[4],b[4];
int main()
{
	int i,j,k,x,y,z;
	scanf("%d:%d:%d",&a[0],&a[1],&a[2]);
	scanf("%d:%d:%d",&b[0],&b[1],&b[2]);
	x=a[0]*60*60+a[1]*60+a[2];
	y=b[0]*60*60+b[1]*60+b[2];
	if(x>=y)y+=24*60*60;
	z=y-x;
	printf("%02d:%02d:%02d",z/(60*60),(z%(60*60))/60,z%60);
}
