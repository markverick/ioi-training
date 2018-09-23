#include<bits/stdc++.h>
using namespace std;
long long a[500135];
int main()
{
    long long i,j,k,n,cot=0,sum=0;
    scanf("%lld",&n);
    cot=n-1;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(&a[1],&a[n+1]);
    for(i=1;i<=n;i++)
    {
        if(sum+a[i]<cot)
        {
            sum+=a[i];
            cot--;
        }
        else
        {
            printf("%lld",cot);
            break;
        }
    }
//    prlong longf("%lld",sum);
}
