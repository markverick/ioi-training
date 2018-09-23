#include<bits/stdc++.h>
using namespace std;
int a[100135],b[100135],hsh[100135],c[100135],d[100135],e[100135],f[100135];
int main()
{
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    int n,i,j,sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        hsh[b[i]]=1;
        if(i<=n/2)
            e[i]=b[i];
        else
            f[i-n/2]=b[i ];
    }
    j=1;
    for(i=1;i<=2*n;i++)
    {
        if(hsh[i]==0)
            a[j++]=i;
    }
    sort(&a[1],&a[n+1]);
    sort(&b[1],&b[n+1]);
    sort(&e[1],&e[n/2+1]);
    sort(&f[1],&f[n/2+1]);
    for(i=n/2+1;i<=n;i++)
    {
        c[i-n/2]=a[i];
    }
    for(i=1;i<=n/2;i++)
    {
        d[i]=a[i];
    }
//    for(i=1;i<=n/2;i++)
//        printf("%d ",c[i]);
//    printf("\n");
//    for(i=1;i<=n/2;i++)
//        printf("%d ",d[i]);
//    printf("\n");
//    for(i=1;i<=n/2;i++)
//        printf("%d ",e[i]);
//    printf("\n");
//    for(i=1;i<=n/2;i++)
//        printf("%d ",f[i]);
//    printf("\n");
//    system("pause");
    i=n/2;
    for(j=n/2;j>=1;j--)
    {
        if(c[i]>e[j])
        {
            sum++;
            i--;
        }
    }
    i=1;
    for(j=1;j<=n/2;j++)
    {
        if(d[i]<f[j])
        {
            sum++;
            i++;
        }
    }
    printf("%d",sum);
}
