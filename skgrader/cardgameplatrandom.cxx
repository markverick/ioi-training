#include<bits/stdc++.h>
using namespace std;
int a[100135],b[100135],hsh[100135],c[100135],d[100135];
int main()
{
    freopen("cardgame.in","r",stdin);
    freopen("cardgame.out","w",stdout);
    srand(137);
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        hsh[b[i]]=1;
    }
    j=1;
    for(i=1;i<=2*n;i++)
    {
        if(hsh[i]==0)
            a[j++]=i;
    }
    sort(&a[1],&a[n+1]);
    int T=n,mid,sum,mc=0,interval=(int)(ceil((double)n*n/10000000));
//    printf("%d\n",interval);
    while(T-=interval)
    {
        sum=0;
//        mid=(rand()*107+rand()*37+rand())%(n+1);
        mid=T;
        mid=max(mid,1);
        for(i=1;i<=mid;i++)
            c[i]=b[i];
        for(i=mid+1;i<=n;i++)
            d[i]=b[i];
        if(mid>=1)
            sort(&c[1],&c[mid+1]);
        if(mid<=n)
            sort(&d[mid+1],&d[n+1]);
        i=n;
        for(j=mid;j>=1;j--)
        {
            if(a[i]>c[j])
            {
                sum++;
                i--;
            }
        }
        i=1;
        for(j=mid+1;j<=n;j++)
        {
            if(a[i]<d[j])
            {
                sum++;
                i++;
            }
        }
        mc=max(mc,sum);
    }
    sort(&b[1],&b[n+1]);
    i=1;
    sum=0;
    for(j=1;j<=n;j++)
    {
        if(a[i]<b[j])
        {
            sum++;
            i++;
        }
    }
    printf("%d",max(mc,sum));
}
