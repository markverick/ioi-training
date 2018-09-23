#include<bits/stdc++.h>
using namespace std;
int a[1000135];
int main()
{
    int i,j,k,n,sum=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)
            return 0;
        sum=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum^=a[i];
        }
        if(sum>0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}
