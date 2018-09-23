#include<bits/stdc++.h>
using namespace std;
int n;
int x[50];
int fu;
int jum[50];
int dp(int idx)
{
    if(jum[idx]>=0)
        return jum[idx];
    if(idx>=n)
    {
        return 0;
    }
    if(fu==1&&idx+2>n)
        return jum[idx]=(dp(idx+1));
    else
        return jum[idx]=max(dp(idx+2)+x[idx],dp(idx+1));


}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x[i]);
        }
        fu=1;
        memset(jum,-1,sizeof jum);

        int a=dp(2)+x[0];
        fu=0;
        memset(jum,-1,sizeof jum);
        int b=dp(1);
        printf("%d\n",max(a,b));
    }
}
