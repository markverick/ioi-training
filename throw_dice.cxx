#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int ka[20135];
int kb[20135];
int main()
{
    int n,m,ha=0,hb=0,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=6;i++)
    {
        scanf("%d",&a[i]);
        ha=max(ha,a[i]);
    }
    scanf("%d",&m);
    for(i=1;i<=6;i++)
    {
        scanf("%d",&b[i]);
        hb=max(hb,b[i]);
    }
    ka[0]=1;
    for(i=1;i<=6;i++)
    {
        for(j=a[i];j<=n*ha;j+=a[i])
        {
            for(k=n*ha;k>=0;k--)
            {
                ka[k+j]+=ka[k];
            }
        }
    }
    for(i=0;i<=n*ha;i++)
    {
        if(ka[i]>0)
            printf("%d\n",i);
    }

}
