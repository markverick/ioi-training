#include<bits/stdc++.h>
using namespace std;
int a[12000];
int b[12000];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,i,j,k;
        scanf("%d %d",&n,&m);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(i=1;i<=m;i++)
            scanf("%d",&b[i]);
        sort(&a[1],&a[n+1]);
        sort(&b[1],&b[m+1]);
        //j=1;
        int fu=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]<=b[i])
            {
                fu=1;break;
            }
        }
        if(fu==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
}
