#include<bits/stdc++.h>
using namespace std;
int a[120000];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    int mn=1000000000;
    long long sum=0;
    a[0]=0;
    int b=a[1];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<a[i-1])
        {
            /*if(a[i]<b)
            {
                b=a[i];
            }*/
        }
        else
        {
            sum+=a[i]-a[i-1];
        }
    }
    printf("%lld",sum);
}
