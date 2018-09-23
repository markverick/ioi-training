#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	//freopen("out.txt","w",stdout);
	//freopen("in.txt","r",stdin);
	int n,i,j,k=1;
	scanf("%d",&n);
	while(n--)
        k*=2;
    printf("%d",(k+1)*(k+1));
}
