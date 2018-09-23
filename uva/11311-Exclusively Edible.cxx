#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,n,m,r,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d %d",&n,&m,&r,&c);
        if(((n-r-1)^(m-c-1)^(r)^(c))>0)
            printf("Gretel\n");
        else
            printf("Hansel\n");
    }
}
