#include<bits/stdc++.h>
int a[150];
int main()
{
    int n;
    int sum=0;
    int i,j,b,c;
    int lowX=300,highX=-100,lowY=300,highY=-100;
    scanf("%d",&n);
    scanf("%d",&c);
    printf("%d ",c);
    a[1]=c;
    for(i=2;i<=n;i++)
    {
        scanf("%d",&b);
        for(j=1;j<=i;j++)
        {
            sum+=a[j];
        }
        a[i]=b*i-sum;
        printf("%d ",b*i-sum);
        sum=0;
    }

}

