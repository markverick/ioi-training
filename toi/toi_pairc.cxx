#include<bits/stdc++.h>
using namespace std;
int a[200135];
int dif[200135];
int n;
int jum[200135][3];
int dp(int idx,int trip)
{
    if(idx==n*2||idx==n*2-1)
    {
        return 0;
    }
    if(jum[idx][trip]>=0)
        return jum[idx][trip];
    int mn=1000000000;
    if(trip==0)
    {
        mn=min(mn,dp(idx+3,1)+dif[idx+3] );
    }
    mn=min(mn,dp(idx+2,trip)+dif[idx+2]);
    return jum[idx][trip]=mn;
}
int main()
{
    int i,j,k,u,x,y;
    scanf("%d",&n);
    for(i=1;i<=n*2+1;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(&a[1],&a[n*2+2]);
    memset(jum,-1,sizeof jum);
    for(j=1;j<n*2+1;j++)
    {
        dif[j]=a[j+1]-a[j];
        //printf("%d ",dif[j]);
    }
    int mn=dp(1,0)+dif[1];
    int sum=0;
    //printf("\n%d\n",mn);
    for(i=2;i<=n*2;i+=2)
    {
        sum+=dif[i];
    }
    printf("%d\n",min(sum,mn));
}
