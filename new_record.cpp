#include<bits/stdc++.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i,j,k;
    int m;
    int hi=0,lo=95000,hc=-1,lc=-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m>hi)
        {
            hi=m;
            hc++;
        }
        if(m<lo)
        {
            lo=m;
            lc++;
        }
    }
    printf("%d %d",hc,lc);
}
