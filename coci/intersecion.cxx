#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	int i,j,k,n,m;
	scanf("%d",&n);
	m=(n-2)*(n-3)/2;
	printf("%d",m*(m-1)/2);
}
