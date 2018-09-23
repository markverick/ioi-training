#include<bits/stdc++.h>
using namespace std;
long long a[12000];
long long qs[12000];

int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        qs[i]=qs[i-1]+a[i];
    }
    int cot=0;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            if(qs[j]-qs[i-1]>0)
            {
                for(k=j+1;k<=n;k++)
                {
                    if(a[k]>0||qs[k]-qs[i-1]<=0)
                    {
                        k--;

                        break;
                    }
                }
                break;
            }
        }
        //printf("%d %d\n",i,k);
        cot++;
        i=k;
    }
    printf("%d\n",cot);
}
