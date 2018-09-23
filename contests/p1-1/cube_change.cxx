#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned long long T,i,j,k,n;
    scanf("%llu",&T);
    while(T--)
    {
        scanf("%llu",&n);
        if(n==1)
            printf("1\n");
        else if(n==2)
            printf("8\n");
        else
            printf("%llu\n",n*n*2+n*(n-2)*2+2*(n-2)*(n-2));
    }
}
