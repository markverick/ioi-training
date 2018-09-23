#include<bits/stdc++.h>
using namespace std;
long long a[100135];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long n,p,i,j,k,T,t,sum,cot;
    scanf("%I64d",&T);
    for(t=1;t<=T;t++)
    {
        j=1;sum=0,cot=0;
        scanf("%I64d %I64d",&n,&p);
        for(i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        for(i=1;i<=n;i++)
        {
            sum+=a[i];
            while(sum>p)
            {
                sum-=a[j];
                j++;
            }
            cot+=(i-j+1);
        }
        printf("Case #%I64d: %I64d\n",t,cot);
    }
}
