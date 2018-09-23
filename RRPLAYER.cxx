#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T,n,i,j,k;
    double x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        x=0;
        for(i=1;i<=n;i++)
        {
            x+=1.0/i;
        }
        printf("%f\n",x*n);
    }
}
