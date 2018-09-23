#include<bits/stdc++.h>
using namespace std;
int n,a[2135],L,W;
double jum[2135][2135];
double blk;
double dp(int l,int r)
{
    if(jum[l][r]>=0)
        return jum[l][r];
    if(l+r==n)
        return 0;
    double mn=100000000;
    if(l+1<=n/2)
        mn=min(mn,dp(l+1,r)+abs((double)a[l+r+1]-blk*l));
    if(r+1<=n/2)
        mn=min(mn,dp(l,r+1)+hypot((double)a[l+r+1]-blk*r,W));
    return jum[l][r]=mn;
}
int main()
{
    int i,j;
    double k;
    while(scanf("%d",&n)!=EOF)
    {
        memset(jum,-1,sizeof jum);
        scanf("%d %d",&L,&W);
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        blk=(double)L/(n/2-1);
        sort(&a[1],&a[n+1]);
        printf("%f\n",dp(0,0));
    }
}
