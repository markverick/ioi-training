#include<bits/stdc++.h>
using namespace std;
int n,a[600],jum[600][600];
int dp(int fst,int lst)
{
    int i;
    if(jum[fst][lst]>=0)
        return jum[fst][lst];
    if(fst+1==lst)
        return abs(a[fst]-a[lst]);
    int mc=0;
    for(i=fst;i<lst;i++)
    {
        mc=max(mc,dp(fst,i)+dp(i+1,lst));
        mc=max(mc,dp(fst,i-1)+dp(i+2,lst)+abs(a[i]-a[i+1]));
    }
    return jum[fst][lst]=mc;
}
int main()
{
    int i,j,k;
    memset(jum,-1,sizeof jum);
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("%d\n",dp(1,n));
}
