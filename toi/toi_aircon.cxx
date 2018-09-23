#include<bits/stdc++.h>
using namespace std;
int a[100135];
int b[100135];
int ms[100135];
int qs[100135];
int main()
{
    int n,m,i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    a[n+1]=m;
    int sum=0;
    for(i=1;i<=n+1;i++)
        ms[i]=-1000000000;
    for(i=1;i<=n+1;i++)
    {
        if(i%2==1)
        {
            sum-=a[i]-a[i-1];
            b[i]=a[i-1]-a[i];
        }
        else
        {
            sum+=a[i]-a[i-1];
            b[i]=a[i]-a[i-1];
        }
       qs[i]=sum;
    }
    int mc=-1000000000;
    for(i=1;i<=n;i++)
    {
        //printf("%d\n",b[i]);
        ms[i]=max(ms[i-1]+b[i],b[i]);
        mc=max(mc,ms[i]);
    }
    printf("%d",sum-2*mc);
}
