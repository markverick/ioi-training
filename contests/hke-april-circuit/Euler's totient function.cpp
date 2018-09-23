#include<bits/stdc++.h>
using namespace std;
double prod[1000135];
int hsh[1000135];
int main()
{
    int i,j,k,T,n;
    for(i=1;i<=1000005;i++)
        prod[i]=1;
    for(i=2;i<=1000005;i++)
    {
        if(hsh[i]==0)
        {
            for(j=i;j<=1000005;j+=i)
            {
                hsh[j]=1;
                prod[j]*=(1.0-1.0/i);
            }
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%.0f\n",prod[n]*n);
    }
}
