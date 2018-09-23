#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,n;
	scanf("%d",&n);
	vector<int> v;
	while(n>0)
    {
        n--;
        v.emplace_back(n%2);
        n/=2;
    }
    for(i=v.size()-1;i>=0;i--)
        printf("%d",v[i]?7:4);
}
