#include<bits/stdc++.h>
using namespace std;
int a[100135],b[100135];
int main()
{
    int n,i,j,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    sort(&a[1],&a[n+1]);
    sort(&b[1],&b[n+1]);
    i=n;
    for(j=n;j>=1;j--)
    {
        if(a[i]>b[j])
        {
            sum+=a[i];
            i--;
        }
    }
    printf("%d",sum);
}
