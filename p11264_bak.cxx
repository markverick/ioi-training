#include<bits/stdc++.h>
using namespace std;
int a[1135];
int qs[1135];
int main()
{
    int T,i,j,k,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        memset(qs,0,sizeof qs);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            qs[i]=qs[i-1]+a[i];
        }
        int sum=0,cot=0;
        for(i=n;i>=1;i--)
        {
            qs[i-1]+=a[i]*(1+qs[i]/a[i])-qs[i];
            if(a[i]*(1+qs[i]/a[i])-qs[i]==1)
                cot++;
        }
        printf("%d\n",cot);
    }
}
