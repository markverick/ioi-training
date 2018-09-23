#include<bits/stdc++.h>
using namespace std;
int qs[100135];
int main()
{
    int n,k,i,a;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        qs[i]=qs[i-1]+a;
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d",&a);
        printf("%d\n",upper_bound(&qs[1],&qs[n+1],a)-&qs[1]);
    }
}
