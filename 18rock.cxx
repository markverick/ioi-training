#include<bits/stdc++.h>
using namespace std;
int a[70];
int jum[70][70];
int dp(int fst,int lst)
{
    if(jum[fst][lst]>=0)
    return jum[fst][lst];
    if(fst==lst+1)
    {
        return 0;
    }
    int mc=0;
    mc=max(mc,dp(fst+2,lst)+a[fst]);
    mc=max(mc,dp(fst+1,lst-1)+a[fst]);
    mc=max(mc,dp(fst,lst-2)+a[lst]);
    mc=max(mc,dp(fst+1,lst-1)+a[lst]);
    return jum[fst][lst]=mc;
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    memset(jum,-1,sizeof jum);
    for(i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("%d",dp(1,n*2));
}
