#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        k=0;
        for(i=1;i<=n;i++)
            scanf("%d",&j),k^=j;
        if(k==0||n%2==0)
            printf("First\n");
        else
            printf("Second\n");
    }
}
