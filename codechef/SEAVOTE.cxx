#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,T,n,a,sum,b;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        sum=0;
        b=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if(a==0)b++;
            sum+=a;
        }
        if(sum>100)
        {
            if(sum-100>=n-b)
                printf("NO\n");
            else
                printf("YES\n");
        }
        else if(sum<100)
            printf("NO\n");
        else
            printf("YES\n");
    }
}
