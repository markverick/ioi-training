#include<bits/stdc++.h>
using namespace std;
int ncr(int n,r)
{
	int sm=1;
	for(i=n;i>n-r;i--)
	{
		sm+=i;
	}
	for(i=2;i<=r;i++)
		sm/=i;
	return sm;
}
int main()
{
	int i,j,k;
	for(i=100;i<=999;i++)
	{
		
	}
}
