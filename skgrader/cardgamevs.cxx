#include<bits/stdc++.h>
using namespace std;
int a[100135],b[100135],hsh[100135],c[100135],d[100135];
int main()
{
//    freopen("cardgame.in","r",stdin);
//    freopen("cardgame.out","w",stdout);
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
    int fst=0,lst=n,mid,x1,y1,x2,y2,mc=0,sum;
    while(fst<=lst)
    {
        mid=(fst+lst)/2;
        for(i=1;i<=mid;i++)
            c[i]=b[i];
        for(i=mid+1;i<=n;i++)
            d[i]=b[i];
        if(mid>=1)
            sort(&c[1],&c[mid+1]);
        if(mid<=n)
            sort(&d[mid+1],&d[n+1]);
        i=mid;sum=0;
        for(j=mid;j>=1;j--)
        {
            if(a[i]>c[j])
            {
                sum++;
                i--;
            }
        }
        x1=sum;
        i=1;sum=0;
        for(j=1;j<=mid;j++)
        {
            if(a[i]<c[j])
            {
                sum++;
                i++;
            }
        }
        x2=sum;
        i=n;sum=0;
        for(j=n;j>=mid+1;j--)
        {
            if(a[i]>d[j])
            {
                sum++;
                i--;
            }
        }
        y1=sum;
        i=mid+1;sum=0;
        for(j=mid+1;j<=n;j++)
        {
            if(a[i]<d[j])
            {
                sum++;
                i++;
            }
        }
        y2=sum;
        mc=max(mc,x1+y2);
        if(x2<y1)
        {
            lst=mid-1;
        }
        else
        {
            fst=mid+1;
        }
    }
    printf("%d",mc);
}

