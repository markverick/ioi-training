#include<bits/stdc++.h>
using namespace std;
int a[1135];
int main()
{
    int T,i,j,k,mn,mc,sum,n;
    scanf("%d",&T);
    while(T--)
    {
        mn=1000000000;mc=0;sum=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            mn=min(mn,a[i]);
            mc=max(mc,a[i]);
            sum+=a[i]-1;
        }
        printf("%d %d\n",mn-1,sum);
    }
}
