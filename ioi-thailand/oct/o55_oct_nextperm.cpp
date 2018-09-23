#include<bits/stdc++.h>
using namespace std;
int a[1135];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    next_permutation(&a[1],&a[n+1]);
    for(i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }
}
