#include<bits/stdc++.h>
using namespace std;
int a[1000135];
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int fst=0,lst=1073741824,mid;
    int mn=1073741824;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        int sum=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]<=mid&&a[i-1]>mid)
            {
                sum++;
            }
        }
    }
}
