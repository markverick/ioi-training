#include<bits/stdc++.h>

int main()
{
    int n,m;
    int i,j,k;
    scanf("%d",&n);
    m=n;
    int cot=1;
    for(i=2;i<=n;i=i*2)
    {
        if(i>n)
        {
            i/2;
            m=i;
            break;
        }
    }
    for(i=m;i>=2;i/=2)
    {
        if(m%2==0)
        {
            printf("%d ",i);
        }
    }
}
