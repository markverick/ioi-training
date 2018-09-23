#include<bits/stdc++.h>
using namespace std;
int a[100135],n;
int dp(int idx)
{
    if(idx>=n)
        return 0;
    return max(dp(idx+2)+a[idx+1],dp(idx+1));
}
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d\n",dp(0));
}
