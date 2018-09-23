#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	int i,j,k,r,c,T,n;
	scanf("%d %d %d",&T,&r,&c);
	k=r*r+c*c;
	while(T--)
    {
        scanf("%d",&n);
        if(n*n<=k)
            printf("DA\n");
        else
            printf("NE\n");
    }
}
