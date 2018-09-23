#include<bits/stdc++.h>
using namespace std;
int hsh[30];
int main()
{
    int n,i,j,k,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a,&b);
        for(j=a;j<b;j++)
        {
            hsh[j]++;
        }
    }
    int mc=0;
    for(i=10;i<=25;i++)
        mc=max(mc,hsh[i]);
    printf("%d",mc);
}
