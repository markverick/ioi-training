#include<bits/stdc++.h>
using namespace std;
int a[100135];
int main()
{
    int n,i,j,k,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    sort(&a[1],&a[n+1]);
//    med=a[(n+1)/2-1];
    int fst=0,mid,lst=1000000000,mc=0;
    while(fst<=lst)
    {
        sum=0;
        mid=(fst+lst)/2;
        for(i=1;i<=n;i++)
        {
            if(mid>a[i])
                sum+=mid-a[i];
        }
        if(sum<=mid)
        {
            mc=max(mc,mid);
            fst=mid+1;
        }
        else
        {
            lst=mid-1;
        }
    }
    printf("%d",mc-1);
}
