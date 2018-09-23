#include<bits/stdc++.h>
using namespace std;

int a[531000];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&a[i]);
    }
    int fst=0,lst=1000000,mid,sum=0,mc=0;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        sum=0;
        if(mid==0)
        {
            printf("0");
            return 0;
        }
        for(i=1;i<=m;i++)
        {
            sum+=a[i]/mid;
        }
//        if(sum==0)
//        {
//            printf("0");
//            return 0;
//        }
        if(sum>=n)
        {
            fst=mid+1;
            mc=max(mc,mid);
        }
        else
        {
            lst=mid-1;
        }
    }
    printf("%d",mc);
}
