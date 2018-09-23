#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define EB emplace_back
using namespace std;

int main()
{
	int i,j,k,n,sq;
    scanf("%d",&n);
    sq=sqrt(n)+1;
    for(i=2;i<=sq;i++)
    {
        if(n%i==0)
        {
            printf("%d",n-n/i);
            return 0;
        }
    }
    if(i==1)
        printf("0");
    else
        printf("%d",n-1);
}
