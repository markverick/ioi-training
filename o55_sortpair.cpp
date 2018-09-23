#include<bits/stdc++.h>
using namespace std;
pair<int,int> a[100135];
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i].first,&a[i].second);
    }
    sort(&a[1],&a[n+1]);
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",a[i].first,a[i].second);
    }
}
