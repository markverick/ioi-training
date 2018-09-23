#include<bits/stdc++.h>
using namespace std;
int a[100135],b[100135],hsh[100135];
int main()
{
    freopen("highcard.in","r",stdin);
    freopen("highcard.out","w",stdout);
    int n,i,j,sum=0;
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
    sort(&b[1],&b[n+1]);
    i=n;
    for(j=n;j>=1;j--)
    {
        if(a[i]>b[j])
        {
            sum++;
            i--;
        }
    }
    printf("%d",sum);
}
