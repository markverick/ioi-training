#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	int i,j,k,n;
	scanf("%d",&n);
	if(n%2==0)
    {
        printf("%d\n",(n/2+1)*(n/2+1));
    }
    else
    {
        printf("%d\n",(n/2+1)*(n/2+1)+(n/2+1));
    }
}
