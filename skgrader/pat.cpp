#include<bits/stdc++.h>
long long a[12000];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    if(n%2==1)
    {
        printf("0");
    }
    else
    {
        n=n/2;
        a[1]=1;
        for(i=1;i<=n;i++)
        {
            a[i+1]=(a[i]*2*((2*i+1))/(i+2))%100000000;
        }
        printf("%lld",a[n]%100000000);
    }
}
