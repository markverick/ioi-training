#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
#define EB emplace_back
using namespace std;

int main()
{
    long long T,i,j,k,n,m,x,y;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld",&n,&m);
        x=n*(n+1)/2;
        if(x>m)
        {
            printf("No\n");
            continue;
        }
        y=__gcd(x,n);
        if(m%y==0)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}
