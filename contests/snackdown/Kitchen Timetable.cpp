#include<bits/stdc++.h>
using namespace std;
int a[10135],b[10135],c[10135];
int main()
{
    int i,j,k,n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            b[i]=a[i]-a[i-1];
        }
        for(i=1;i<=n;i++)
        {
            scanf("%d",&c[i]);
        }
        int cot=0;
        for(i=1;i<=n;i++)
        {
            if(c[i]<=b[i])cot++;
        }
        printf("%d\n",cot);
    }
}
