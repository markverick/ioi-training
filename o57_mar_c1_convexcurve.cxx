#include<bits/stdc++.h>
using namespace std;
int n,h[5135];
int dp(int slope,int v)
{
    if(v>=n+1)
    {
        return 0;
    }
    int mc=0,i;
    for(i=v+1;i<=n;i++)
    {
        if(slope>=h[i]-h[v])
        {
            mc=max(mc,dp(min(slope,(h[i]-h[v])/(i-v)),i)+1);
        }
    }
    mc=max(mc,dp(0,n+1)+1);
    return mc;
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    h[0]=-1000000000;
    h[n+1]=-1000000000;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&h[i]);
    }
    int mc=0;
    for(i=1;i<=n;i++)
    {
        mc=max(mc,dp(100000000,i));
    }
    printf("%d\n",mc);
}
